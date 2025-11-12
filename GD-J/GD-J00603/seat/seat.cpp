#include<bits/stdc++.h>
using namespace std;
int a[109];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a1,p,x,y;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];
	sort(a+1,a+(n*m)+1);
	for(int i=0;i<=n*m;i++){
		if(a[i]==a1){
			p=n*m-i+1;
			break;
		}
	}
	if(p%n==0) x=p/n;
	else x=p/n+1;
	if(x%2==1) y=p-(n*(x-1));
	else y=n-(p-(n*(x-1)))+1;
	cout<<x<<" "<<y;
	return 0;
}
