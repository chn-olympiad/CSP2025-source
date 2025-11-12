#include<bits/stdc++.h>
using namespace std;
namespace code{
#define F(i,x,y) for(int i=x,__=y;i<=__;i++)
#define R(i,x,y) for(int i=y,__=x;i>=__;i--)
#define debug(x) cerr<<#x<<"="<<x<<endl
	using ll=long long;
	using uint=unsigned int;
	using ull=unsigned long long;
	const int N=505;
	int a[N],c[N];
	string s;
	bool check(int n,int m){
		int sum=0,time=0;
		F(i,1,n){
			if(c[a[i]]<=time){
				time++;
			}
			else {
				sum+=(s[i]=='1');
				time+=(s[i]=='0');
			}
		}
		return sum>=m;
	}
	int main(){
		freopen("employ.in","r",stdin);
		freopen("employ.out","w",stdout);
		cin.tie(0)->sync_with_stdio(0);
		int n,m;
		cin>>n>>m;
		cin>>s;
		s=' '+s;
		F(i,1,n)cin>>c[i];
		F(i,1,n)a[i]=i;
		int ans=0;
		do{
			ans+=check(n,m);
		}while(next_permutation(a+1,a+1+n)!=0);
		cout<<ans;
		return 0;
	}
}
int main(){
	code::main();
	return 0;
}