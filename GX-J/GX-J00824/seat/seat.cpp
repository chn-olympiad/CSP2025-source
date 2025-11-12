#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,num;
};
int n,m;
node a[105];
node f[15][15];
bool cmp(node a,node b){
	return a.num>b.num;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].num;
		a[i].id=i;
	}
	sort(a+1,a+1+(n*m),cmp);
	for(int i=1;i<=n*m;i++){
		int ff=i/n;
		if(ff*n!=i) ff++;
		if(ff%2==1){
			int x=i%n;
			if(x==0) x=n;
			f[x][ff]=a[i];
		}
		else{
			int x=i%n;
			if(x==0) x=n;
			f[n-x+1][ff]=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(f[i][j].id==1){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	return 0;
}
