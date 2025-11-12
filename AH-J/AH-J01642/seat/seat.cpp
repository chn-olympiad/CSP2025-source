#include"bits/stdc++.h"
using namespace std;
const int N=15,M=15;
struct node{
	int grade,id;
}a[N*M];
int n,m,mp[N][M];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;++i){
		cin>>a[i].grade;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,[](node a,node b){
		return a.grade>b.grade;
	});
	for(int i=1,cnt=1;i<=m;++i){
	if(i&1)
		for(int j=1;j<=n;++j,++cnt)
		mp[j][i]=a[cnt].id;
	else for(int j=n;j>=1;--j,++cnt)
		mp[j][i]=a[cnt].id;
	}	
	int x=0,y=0;
	for(int i=1;i<=n&&x==0;++i){
		for(int j=1;j<=m&&y==0;++j)
		if(mp[i][j]==1)x=i,y=j;
	}
	cout<<y<<" "<<x;
}
