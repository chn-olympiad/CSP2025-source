#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
int n,m;
struct node{
	int x,idd;
}a[N];
bool cmp(node u,node v){
	return u.x>v.x;
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int p=(i-1)*n+j;
			a[p].idd=p;
			cin>>a[p].x;
		}
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		int flag=0;
		if(i&1){
			for(int j=1;j<=m;j++){
				int p=(i-1)*n+j;
				if(a[p].idd==1){
					cout<<i<<' '<<j;
					flag=1;
					break;
				}
			}
		}else{
			for(int j=1;j<=m;j++){
				int p=(i-1)*n+j;
				if(a[p].idd==1){
					cout<<i<<' '<<m-j+1;
					flag=1;
					break;
				}
			}
		}
		if(flag) break;
	}
	return 0;
}
