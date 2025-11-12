#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,tmp;
}a[10005];
bool cmp(node a,node b){
	return a.tmp>b.tmp;
}
int t[105][105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].tmp;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int nx=1,ny=1;
	int nd=1;
	for(int i=1;i<=n*m;i++){
		t[nx][ny]=a[i].id;
		if(nx+nd<1||nx+nd>n){
			ny++;
			nd=-nd;
		}
		else{
			nx+=nd;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(t[i][j]==1){
				cout<<j<<' '<<i;
				return 0;
			}
		}
	}
	return 0;
}
