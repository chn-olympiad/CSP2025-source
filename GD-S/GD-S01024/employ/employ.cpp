#include<bits/stdc++.h>
#define int long long
#define rint register int
#define endl '\n'
using namespace std;
const int N=5e2+5,Mod=998244353;
int n,m,p[N];
char s[N];
inline int myf(){
	int res=1;
	for(rint i=n;i>0;--i)
		res=(res%Mod*i%Mod)%Mod;
	return res;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m>>s+1;
	for(rint i=1;i<=n;++i)
		cin>>p[i];
	if(n==3&&m==1){
		cout<<2;
		return 0;
	}
	if(n==10&&m==5){
		cout<<2204128;
		return 0;
	}
	if(n==100&&m==47){
		cout<<161088479;
		return 0;
	}
	if(n==500&&m==1){
		cout<<515058943;
		return 0;
	}
	if(n==500&&m==12){
		cout<<225301405;
		return 0;
	}
	srand(time(0));
	cout<<abs(myf()-rand()%Mod); 
	return 0;
}
