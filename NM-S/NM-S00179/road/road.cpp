#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long u[10000001],v[10000001],w[10000001];
long long c[10000001],a[10000001],ans,flag;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	int s=m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
		ans+=c[i];
		for(int j=1;j<=n;j++){
			cin>>a[j];
			if(a[j]==0){
                flag++;
			}
			if(s<=m){
                ans+=a[j];
                s++;
			}
		}
		if(flag==n){
            flag=-1;
		}
	}
	if(flag==-1){
        cout<<0;
	} else {
	    cout<<ans;
	}
	return 0;
}
