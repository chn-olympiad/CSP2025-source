#include<bits/stdc++.h>
using namespace std;
int n,m,k=1;
struct node{
	int cj,id;
}a[1005];
int b[1005][1005],c[1005][1005];
bool cmp(node x,node y){
	return x.cj>y.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].cj;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
//	for(int i=1;i<=n*m;i++){
//		cout<<a[i].id<<"+ ";
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
		if(i%2==0){
			c[i][m-k%m+1]=a[k].id;
			//cout<<k<<" ";
		}
		else{
			c[i][j]=a[k].id;
			
		}
		k++;
	}
		
			

}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]==1){
				cout<<i<<" "<<j;
				return 0;
			}
		}
	}
	cout<<0;
	return 0;
} 
