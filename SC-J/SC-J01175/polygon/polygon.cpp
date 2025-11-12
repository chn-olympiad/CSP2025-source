#include<bits/stdc++.h>
using namespace std;
int n,a[5500],b[5500],cnt,i,j;
void dfs(int m,int z){
	if(j+m<n){
		if(z>a[j+m]&&b[j+m]==0) cnt++;
		if(b[j+m]==0){
			b[j+m]=1;
			dfs(m+1,z+a[j+m]);
		}
		b[j+m]=1;
		dfs(m+1,z);
		b[j+m]=0;
	}
	return;
}
int main(){
	int m,z;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int v=0;v<n;v++){
		cin>>a[v];
	}
	sort(a,a+n);
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			z=a[i]+a[j];
			b[i]=1,b[j]=1;
			dfs(1,z);
			b[i]=0,b[j]=0;
		}
	}
	cout<<cnt;
	return 0;
}