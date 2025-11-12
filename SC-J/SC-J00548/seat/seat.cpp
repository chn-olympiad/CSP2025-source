#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,id;
}a[105];
int n,m,cnt;
bool cmp(node x,node y){
	return x.x>y.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;	
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(i&1){
			for(int j=1;j<=m;j++){
				if(a[++cnt].id==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		else{
			for(int j=m;j>=1;j--){
				if(a[++cnt].id==1){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}