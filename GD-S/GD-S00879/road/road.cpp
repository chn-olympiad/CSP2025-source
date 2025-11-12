#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
struct stu{
	ll v,w;
};
ll n,m,k,sum;
ll dis[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		ll x,y,z;
		cin>>x>>y>>dis[i];
	}
	while(k--){
		cin>>m;
		for(int i=1;i<=n;i++){
			ll x,y,z;
			cin>>x;
		}
	}
	sort(dis+1,dis+1+n);
	for(int i=1;i<n;i++){
		sum+=dis[i];
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

