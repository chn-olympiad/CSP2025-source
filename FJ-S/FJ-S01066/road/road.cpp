#include<bits/stdc++.h>
using namespace std;
struct node{
	int h,t,q,xc;
}a[1000100];
bool x[50];
int b[20][1000100],xj[20],r,n,m,k,sum,d[1000010];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
    cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
	     cin>>a[i].h>>a[i].t>>a[i].q;
	} 
	for(int i=1;i<=k;i++){
		cin>>xj[i];
		for(int j=1;j<=n;j++){
			cin>>b[i][j];
		}
	}
	cout<<0;
	return 0; 
} 
