#include<bits/stdc++.h>
using namespace std;
int n,m,id;
int a[105],b[15][15];
bool cmp(int l,int r){
	return l>r;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i=0;i<=104;i++){
		a[i]=-1;
	}
	cin>>n>>m;
	cin>>id;
	for(int i=2;i<=n*m;i++){
		cin>>a[i];
	}
	a[1]=id;
	sort(a+1,a+104,cmp);
	for(int i=1;i<=n*m;i++){
		int x;
		int p=i%n,q=i%(n*2),y=(i-1)/n+1;
		if(p==0)p=n;
		if(q==0)q=2*n;
		if(p==q)x=p;
		else if(p==0&&q!=0)x=p;
		else x=2*n-q+1;
		b[x][y]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==id){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	
	return 0;
}
