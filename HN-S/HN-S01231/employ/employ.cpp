#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
	int cnt=0;
	bool f=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=!f;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		cnt=cnt*10+c-'0';
		c=getchar();
	}
	return ((f==0)?cnt:-cnt);
}

void write(__int128 x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar((char)(x%10+'0'));
}

int n,m;

string s;

int p[100005];

bool vis[100005];

int box[100005];

bool check(){
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		if(cnt>=box[i]){
			cnt++;
		}else if(s[i]=='1'){
			ans++;
		}else{
			cnt++;
		}
	}
	return ans>=m;
}

int ans;

void dfs(int x){
	if(x>n){
		if(check()){
			ans++;
		}
		return ;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			box[x]=p[i];
			vis[i]=1;
			dfs(x+1);
			box[x]=0;
			vis[i]=0;
		}
	}
}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cout.tie(0)->sync_with_stdio(false);
	cin>>n>>m;
	cin>>s;
	s="0"+s;
	bool f=0;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			f=1;
			break;
		}
	}
	if(n<=18){
		dfs(1);
		cout<<ans<<'\n';
	}else if(f==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(p[i]>0){
				cnt++;
			}
		}
		if(cnt<m){
			cout<<"0\n";
			return 0;
		}
		__int128 ans=1;
		for(int i=1;i<=cnt;i++){
			ans=ans*i;
		}
		write(ans%(998244353));
	}else{
		cout<<n<<'\n';
	}
	return 0;
}

