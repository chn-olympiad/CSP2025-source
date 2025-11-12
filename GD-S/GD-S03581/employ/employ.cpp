#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=(int)b;i++)
#define ROF(i,a,b) for(int i=b;i>=(int)a;i--)
const int N=1e6+10;
const ll inf=1e9+10;
const ll mod=1e9+7;
using Vl=vector<ll>;
using PI=array<ll,2>;
ll n,m,c[N],id[N],ans=0,ct;
string s;
bool cmp(int x,int y){return x<y;}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;s=' '+s;
	FOR(i,1,n) cin>>c[i],id[i]=i;
	if(n<=10){
		do{
			ll res=0;
			FOR(i,1,n){
				if(s[i]=='0') res++;
				else if(c[id[i]]<=res) res++;
			}		
//			cout<<res<<'\n';	
//			if(n-res>=m) FOR(i,1,n) cout<<id[i]<<" \n"[i==n];
			ans+=((n-res)>=m);
		}while(next_permutation(id+1,id+n+1));
		cout<<ans<<'\n';return 0;
	}
	cout<<"0\n";
	return 0;
}
/*
3 2
101
1 1 2

10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
