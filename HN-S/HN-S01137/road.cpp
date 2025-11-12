#include<bits/stdc++.h>
using namespace std;
int a[100000][100000],o[100005];
int main(){
	long long d,f,c=0,n,m,k,t;
	freopen("road.in","r","stdin");
	freopen("road.out","w","stdout");
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
	    cin>>d>>f;
		cin>>a[d][f];	
	}
	for(int i=1;i<=n+1;i++){
		cin>>o[i];
	}
	for(int i=1;i<=n;i++){
		c=c+a[i][n-i]-o[i];
	}
	cout<<c;
	return 0;
}
