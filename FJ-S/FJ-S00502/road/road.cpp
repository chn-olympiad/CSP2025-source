#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int u[N];
int v[N];
int w[N];
int c[N];
int a[N];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
		sum+=w[i];
	}
    for(int i=1;i<=k;i++){
    	cin>>c[i];
    	for(int j=1;j<=n;j++){
    		cin>>a[j];
		}
	}
	cout<<sum;
	return 0;
}
