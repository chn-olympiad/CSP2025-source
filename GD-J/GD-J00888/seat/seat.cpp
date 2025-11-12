#include<bits/stdc++.h>
using namespace std;
struct node{
	int d,f;
}a[200];
bool cmp(node x,node y){
	return x.f>y.f; 
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].f;
		a[i].d=i;
	}
	int ok=1;
	int x=0;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n;i++){
		if(ok==1){
			for(int j=1;j<=m;j++){
				x++;
				if(a[x].d==1){
					cout<<i<<' '<<j;
					return 0; 
				}
			}
			ok=0;
		}
		else {
			for(int j=m;j>=0;j--){
				x++;
				if(a[x].d==1){
					cout<<i<<' '<<j;
					return 0; 
				}
			}
			ok=1;
		}
	}
	return 0;
}

