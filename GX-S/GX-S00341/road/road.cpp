#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,sum=0;
	int u[100101],v[101001],w[100101];
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=m;i++){
		sum+=w[i];
	}
	cout<<sum;
	//wo yao shang 2 deng awa
	return 0;
}
