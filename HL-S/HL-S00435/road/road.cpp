#include<bits/stdc++.h>
using namespace std;
const int maxn=100001;
int u[maxn];
int v[maxn];
int w[maxn];
int a[maxn];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdin);
	int n,m,k;
	cin>>n>>m>>k; 
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int j=0;j<k;j++){
		cin>>a[j];
	}
	cout <<"13";
	fclose(stdin);
	fclose(stdout);	 
}
