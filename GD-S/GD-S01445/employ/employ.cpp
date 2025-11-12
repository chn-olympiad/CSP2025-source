#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
const int N=505,M=3e5+10;
namespace zyh{
	struct md{
		ll val;
		friend md operator+(md a,md b){return {(a.val+b.val)%mod};}
		friend md operator*(md a,md b){return {(a.val*b.val)%mod};}
	}f[M][20];
	char str[N];
	int c[N];
	int n,m;
	md ans;
	bool flag=1;
	int p[N];	
	signed lqr(){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>str[i];
			if(str[i]=='0') flag=0;
		}
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		if(flag){
			ans={1};
			for(int i=1;i<=n;i++){
				ans=ans*md({1});
			}
			cout<<ans.val;
			return 0;
		}
		if(n<=10){
			int tmp=1,res=0;
			for(int i=1;i<=n;i++){
				p[i]=i;
				tmp*=i;
			}
			for(int i=1;i<=tmp;i++){
				next_permutation(p+1,p+n+1);
				int cnt=0;
				for(int j=1;j<=n;j++){
//					cout<<p[j]<<' ';
					if(cnt>=c[p[j]]||str[j]=='0') cnt++;
				}
//				cout<<n-cnt<<'\n';
				if(n-cnt>=m) res++;
			}			
			cout<<res;
			return 0;
		}
		if(n<=18){
			f[0][0]={1}; 
			for(int i=1;i<(1<<n);i++){
				int cnt=0;
				for(int j=0;j<n;j++) if(i&(1<<j)) cnt++;
				for(int j=0;j<=cnt;j++){
					for(int k=1;k<=n;k++){
						if(i&(1<<(k-1))){
							if(j<c[k]&&str[cnt]=='1') f[i][j]=f[i][j]+f[i-(1<<(k-1))][j];
							else if(j) f[i][j]=f[i][j]+f[i-(1<<(k-1))][j-1];
						}
					}
				}
			}
//			for(int i=0;i<n;i++){
//				cout<<f[1<<i][1].val<<' ';
//			}
//			cout<<'\n';
			for(int i=0;i<=n-m;i++){
//				cout<<f[1<<(n-1)][i].val<<' ';
				ans=ans+f[1<<(n-1)][i];
			}
//			cout<<'\n';
			cout<<ans.val;
			return 0;
		}
		return 0; 
	}
}
void file_io(string str){
	string s1=str+".in",s2=str+".out";
	freopen(s1.c_str(),"r",stdin);
	freopen(s2.c_str(),"w",stdout);
}
signed main(){
	file_io("employ");
	return zyh::lqr();
}
//28 pts
