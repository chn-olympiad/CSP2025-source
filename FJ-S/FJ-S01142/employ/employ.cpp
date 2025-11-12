#include<bits/stdc++.h>
#define int long long
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int mod=998244353;
const int N=505;
int n,m,c[N],ans;
string s;
struct Sub1{
	int a[N];
	bool flag[N];
	void dfs(int step){
		if(step==n){
			int sum=0,cnt=0;
			for(int i=1;i<=n;i++){
				if(s[i]=='1'&&sum<c[a[i]])cnt++;
				else sum++;
			}
//			cout<<"?"<<cnt<<" "<<sum<<'\n';
			if(cnt>=m){
//				for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//				cout<<'\n';
				ans++;
			}
			return;
		}
		for(int i=1;i<=n;i++){
			if(!flag[i]){
				a[step+1]=i;flag[i]=1;
				dfs(step+1);flag[i]=0;
			}
		}
	}	
}T1;
bool M1;
struct Sub2{
	int f[2][20][(1<<18)+2];
	void add(int &x,int y){
		x+=y;x%=mod;
	}
	void work(){
		f[0][0][0]=1;
//		cerr<<"!"<<n<<" "<<m<<'\n';
		for(int i=1;i<=n;i++){
			int now=(i&1),lst=(now^1);
//			cerr<<"?"<<i<<'\n';
			for(int j=0;j<(1<<n);j++){//last
				if(__builtin_popcount(j)!=i-1)continue;
			//	cerr<<"?"<<i<<" "<<j<<'\n';
				for(int k=1;k<=n;k++){//·Åk 
					if(j&(1<<(k-1)))continue;
					int S=(j|(1<<(k-1)));
					for(int p=0;p<=i;p++){
						bool flag=1;
						if(s[i]=='0'||p>=c[k])flag=0;
						if(flag)add(f[now][p][S],f[lst][p][j]);
						else add(f[now][p+1][S],f[lst][p][j]);
					}
				}
			}
//			cerr<<"!"<<'\n';
			for(int j=0;j<=n;j++){
				for(int k=0;k<(1<<n);k++)f[lst][j][k]=0;
			}
//			cerr<<"!"<<'\n';
		}
		int ans=0;
		for(int i=0;i<=n-m;i++){
			add(ans,f[n&1][i][(1<<n)-1]);
		}
		cout<<ans<<'\n';
	}
}T2;
bool M2;
void solve(){
	n=read();m=read();
	cin>>s;s='#'+s;
	for(int i=1;i<=n;i++)c[i]=read();
	if(n<=10)T1.dfs(0),cout<<ans<<'\n';
	else T2.work();
}
signed main(){
	//freopen("data.in","r",stdin);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int T;T=1;while(T--)solve();
	//cerr<<1.0*clock()/CLOCKS_PER_SEC<<"ms"<<'\n';
	//cerr<<abs(&M1-&M2)/1024/1024<<'\n';
	return 0;
}

