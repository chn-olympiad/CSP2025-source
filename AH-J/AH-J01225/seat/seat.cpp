#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[114514];
int x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m*n;i++)cin>>a[i];
	x=1;
	for(int i=2;i<=m*n;i++)if(a[1]<a[i])x++;
	int p,q;
	p=x/n;
	q=x%n;
	if(p%2==0){
		if(q==0){
			cout<<p<<" "<<"1";
		}
		else{
			cout<<p+1<<" "<<q;
		}
	}
	if(p%2==1){
		if(q==0){
			cout<<p<<" "<<n;
		}
		else{
			cout<<p+1<<" "<<n-q+1;
		}
	}
	return 0;
}
