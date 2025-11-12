#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,x;
}a[10005];
bool cmp(node tx,node ty){
	if(tx.x==ty.x) return tx.id<ty.id;
	return tx.x>ty.x;
}
int n,m,wz[15][15];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int t;
			if(j%2) t=n*(j-1)+i;
			else t=n*j-i+1;
			if(a[t].id==1){
				cout<<j<<" "<<i;
				return 0; 
			}
		}
	}
	return 0;
} 
