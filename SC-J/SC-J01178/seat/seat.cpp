#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[105][105],b[1005],t;
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	int n,m;cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	} 
	t=b[1];
	sort(b+1,b+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if((i/n)%2==1){
			if(i%n==0) a[n][i/n-1]=b[i];
			else a[n-i%n+1][i/n]=b[i];
		}
		else{
			if(i%n==0) a[1][i/n-1]=b[i];
			else a[i%n][i/n]=b[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]==t) cout<<j+1<<" "<<i;
		}
	}
	return 0;
}