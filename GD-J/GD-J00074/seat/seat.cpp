#include <bits/stdc++.h>
using namespace std;
const int N=120;
struct node{
	int fz;
	int id;
}a[N];
int n,m;
bool cmp(node x,node y){
	return x.fz>y.fz;
}
int ma[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int s=n*m;
	for(int i=1;i<=s;i++){
		cin>>a[i].fz;
		a[i].id=i;
	}
	sort(a+1,a+s+1,cmp);
	
	int cnt=1;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				ma[j][i]=a[cnt++].id;
			}
		}
		else if(i%2==0){
			for(int j=n;j>=1;j--){
				ma[j][i]=a[cnt++].id;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(ma[i][j]==1){
				cout<<j<<" "<<i;
				return 0;
			}
		}
	}
	fclose(stdout);
	fclose(stdout);
	return 0;
}

