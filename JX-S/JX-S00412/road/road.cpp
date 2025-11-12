#include<bits/stdc++.h>

#define ll long long
#define rui register unsigned int
#define ris(x,y,z) for(rui x=y;x<y+1;++x)
#define ful(x,y,z) for(rui x=y;x>y-1;--x)
#define db double

using namespace std;

const ll N=1e5+5;

ll n,m,k,ans=0;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;++i){
		ll a,b,c;
		cin>>a>>b>>c;
		ans+=c;
	}
	cout<<ans;
	return 0;
}
