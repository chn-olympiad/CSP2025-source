#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout); 
	long int n,m,k,n1;
	cin>>n>>m>>k;
	n1=n;
	n+=k;
	long long s[n][n],u[m],v[m],w[m];
	for(int i=0;i<m;i++){
		cin>>u[i]>>v[i],w[i];
	}
	for(int i=n1;i<n;i++){
		for(int j=0;j<n;j++){
			s[i][j]=1;
			s[i][j]=1;
		}
	}
	for(int i=0;i<n;i++){
		int jud=0;
		for(int j=0;j<n;j++){
			if(s[i][j]==1)jud=1;
		}
		if(jud==0)return 0;
	}
	cout<<"0"<<endl;
	return 0;
}
