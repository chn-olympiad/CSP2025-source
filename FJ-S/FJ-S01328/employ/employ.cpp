#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353,N=5e2+10;
ll n,m,jie,c[N],p[N],ba,ans;
bool b[N];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='1') b[i]=1;
		else b[i]=0;
	}
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=n;i++) p[i]=i;
	if(n>20){
		for(int i=1;i<=n;i++){
			if(!b[i]){
				cout<<0<<"\n";
				return 0;
			}
			if(!c[i]){
				cout<<0<<"\n";
				return 0;
			}
		}
		jie=1;
		for(int i=1;i<=n;i++){
			jie=jie*i%mod;
		}
		cout<<jie<<"\n";
		return 0;
	}
	do{
		ba=0;
		for(int i=1;i<=n;i++){
			if(b[i]&&c[p[i]]>ba) continue; 
			else ba++;
		}
		if(ba<=n-m) ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<"\n";
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3

7 5
1111111
1 3 7 1 6 4 2
*/
