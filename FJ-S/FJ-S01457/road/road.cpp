#include<bits/stdc++.h>
using namespace std;
int u[1000005],v[1000005],w[1000005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    int n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
    	cin>>u[i]>>v[i]>>w[i];
	}
	long long mm[100];
	bool l=false;
	for(int i=1;i<=k;i++){
		cin>>mm[i];
		int a;
		for(int kk=1;kk<=n;kk++){
		cin>>a;
		mm[i]+=a;
	}}
	sort(mm+1,mm+k+1);
		sort(w+1,w+m+1);
		long long ans=0;
		for(int i=1;i<=m;i++){
			ans+=w[i];
		}
		cout<<min(mm[1],ans);
	return 0;
}
