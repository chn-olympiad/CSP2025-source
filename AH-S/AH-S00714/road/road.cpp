#include<bits/stdc++.h>
using namespace std;
int n,m,k,r[10005][3],c[10005],w[1000005][3],sum;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>r[i][1]>>r[i][2]>>c[i];
		sum+=c[i];
	}
	for(int i=1;i<=k;i++)cin>>w[i][1]>>w[i][2];
	cout<<sum<<endl;
	return  0;
}

