#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MaxN=500,Mod=998244353;
int n,m,c[MaxN+1];
char s[MaxN+1];
namespace SolveA{
int a[MaxN+1];
void Solve(){
	for(int i=1;i<=n;i++)a[i]=i;
	int ans=0;
	do{
		int totd=0;
		for(int i=1;i<=n&&n-totd>=m;i++){
			if(s[i]=='0'||totd>=c[a[i]])totd++;
		}
		if(n-totd>=m)ans++;
	}while(next_permutation(a+1,a+1+n));
	cout<<ans;
}

}
void Solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>c[i];
	if(n<=10)return SolveA::Solve();
	if(n==m){
		bool flag=true;
		for(int i=1;i<=n&&flag;i++)flag&=(s[i]=='1');
		if(flag){
			int ans=1;
			for(int i=1;i<=n;i++)ans=ans*i%Mod;
			cout<<ans<<'\n';
		}else cout<<0;
		return;
	}
}
#undef int
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
//	int T;
//	cin>>T;
//	while(T--)
		Solve();
	return 0;
}

