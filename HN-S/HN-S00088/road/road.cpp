#include <bits/stdc++.h>
using namespace std;
int n,m,k,U[1000005],V[1000005],P[1000005],cun[10][10005]; 
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	long long sum=0;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>U[i]>>V[i]>>P[i];
		sum+=P[i]; 
	}
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			cin>>cun[i][j]; 
		}
	}
	cout<<sum<<endl;
	return 0;
}

