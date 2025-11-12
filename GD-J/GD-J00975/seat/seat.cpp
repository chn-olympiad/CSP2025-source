#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,x;
}a[1010];
bool cmp(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	int nx=1,ny=0;
	for(int i=1;i<=n*m;i++){
		if(nx%2==0){
			if(ny==1){
				nx++;
			}else{
				ny--;
			}
		}else{
			if(ny==n){
				nx++;
			}else{
				ny++;
			}
		}
		if(a[i].id==1){
			cout<<nx<<' '<<ny;
			return 0;
		}
	}
	return 0;
}
