#include<bits/stdc++.h>
using namespace std;
long long a[10001],b[10001],c[10001],n,m,k,u[10001],v[10001],qs=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(long long i=0;i<k;i++){
		cin>>u[i];
		for(int j=1;j<n;j++){
			cin>>v[j];
		}
	}
	for(long long i=0;i<m;i++){
		if(a[i]==a[i+1]||b[i]==b[i+1]){
			if(c[i]>c[i+1]&&c[i]>u[i]+v[c[i]]){
			c[i]=0;
				}
			}
		if(a[i]==a[i-1]||b[i]==b[i-1]){
			if(c[i]>c[i-1]){
			c[i]=0;
				}
			}
		}
		for(long long i=0;i<m;i++){
			qs+=c[i];
		}
		cout<<qs;
		fclose(stdin);
		fclose(stdout);
		return 0;
}
