#include<bits/stdc++.h>
using namespace std;
int n,m,k,u[1000010],v[1000010],w[100010],c,arr[100010];
long long s=0;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>u[i]>>v[i]>>w[i];
	for(int i=1;i<=k;i++){
		cin>>c;
		for(int i=1;i<=n;i++){
			cin>>arr[i];
		}
	} 
	if(k==0){
		for(int i=1;i<=m;i++){
			s+=w[i];
		}
	}
	cout<<s;
	return 0;
} 
