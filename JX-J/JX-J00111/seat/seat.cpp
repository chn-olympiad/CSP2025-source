#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int n,m,cnt=1;
struct node{
	int ach,id;
}a[N];
bool cmp(node c,node d){
	return c.ach>d.ach;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].ach;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i%2==1)
			for(int j=1;j<=m;j++){
				if(a[n*(i-1)+j].id==1){
					cout<<i<<" "<<j;
				}
			}
		else
			for(int j=m;j>=1;j--){
				if(a[n*(i-1)+(n-j+1)].id==1){
					cout<<i<<" "<<j;
				}
			}
	}
	return 0;
}
