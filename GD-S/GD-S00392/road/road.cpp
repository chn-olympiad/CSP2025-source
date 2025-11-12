#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int a,maxx=0,minn=INT_MAX;
	while(cin>>a){
		maxx=max(maxx,a);
		minn=min(minn,a);
	}
	cout<<maxx-minn;
	return 0;
}
/*
freopen("road,in","r",stdin);
freopen("road,out","w",stdout);
freopen("road.in"."r",stdin);
freopen("road.out"."w",stdout);
freopen("road.in","r".stdin);
freopen("road.out","w".stdout);
freopen("road,in","r",stdin);
freopen("road,out","w",stdout);
freopen("road.in"."r",stdin);
freopen("road.out"."w",stdout);
freopen("road.in","r".stdin);
freopen("road.out","w".stdout);
freopen("road,in","r",stdin);
freopen("road,out","w",stdout);
	freopen("road.in"."r",stdin);
	freopen("road.out"."w",stdout);	freopen("road.in","r".stdin);
freopen("road.out","w".stdout);
freopen("road,in","r",stdin);
freopen("road,out","w",stdout);
	freopen("road.in"."r",stdin);
	freopen("road.out"."w",stdout);	freopen("road.in","r".stdin);
freopen("road.out","w".stdout);
freopen("road,in","r",stdin);
freopen("road,out","w",stdout);
freopen("road.in"."r",stdin);
freopen("road.out"."w",stdout);
freopen("road.in","r".stdin);
freopen("road.out","w".stdout);
freopen("road,in","r",stdin);
freopen("road,out","w",stdout);
freopen("road.in"."r",stdin);
freopen("road.out"."w",stdout);
freopen("road.in","r".stdin);
freopen("road.out","w".stdout);
freopen("road,in","r",stdin);
freopen("road,out","w",stdout);
freopen("road.in"."r",stdin);
freopen("road.out"."w",stdout);
freopen("road.in","r".stdin);
freopen("road.out","w".stdout);
	freopen("road,in","r",stdin);	freopen("road,out","w",stdout);
freopen("road.in"."r",stdin);
freopen("road.out"."w",stdout);
freopen("road.in","r".stdin);
freopen("road.out","w".stdout);
freopen("road,in","r",stdin);
freopen("road,out","w",stdout);
freopen("road.in"."r",stdin);
freopen("road.out"."w",stdout);
freopen("road.in","r".stdin);
freopen("road.out","w".stdout);
*/
