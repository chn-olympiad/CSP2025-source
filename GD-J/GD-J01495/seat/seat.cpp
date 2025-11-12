#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105]; 
int dx[]{1,0,-1};
int dy[]{0,1,0};
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    cin>>n>>m;
    int d=0;
	for(int k=1;k<=n*m;k++){
		cin>>a[k];
		if(k==1)d=a[k];
	}	
	sort(a+1,a+n*m+1,cmp);
	int cnt=0,g=0;
	while(g<=m){
		g++;
		if(g%2==1){
			for(int k=1;k<=n;k++){
			    if(a[++cnt]==d){
			    	cout<<g<<" "<<k;
			    	return 0;
				}
			}
		}
		if(g%2==0){
			for(int k=n;k>=1;k--){
			    if(a[++cnt]==d){
			    	cout<<g<<" "<<k;
			    	return 0;
				}
			}
		}
	}
	return 0;
}
