#include<bits/stdc++.h>
using namespace std;
int n,m,b;
struct node{
	int sum,id;
}a[111];
bool cmp(node x,node y){
	if(x.sum>y.sum) return true;
	return false;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sum;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=0;i<m;i++){
		b++;
		for(int j=1;j<=n;j++){
			if(a[i*n+j].id==1&&b%2==0){
				cout<<i+1<<" "<<n-j+1;
			}
			if(a[i*n+j].id==1&&b%2==1){
				cout<<i+1<<" "<<j;
			}
		}
	}
	return 0;
}
