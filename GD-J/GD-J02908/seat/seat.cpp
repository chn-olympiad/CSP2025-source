#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,a[1000]={0},x,b[1000];
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>b[i];
	x=b[1];
	sort(b+1,b+1+n*m);
	for(int i=1;i<=n*m;i++)a[i]=b[n*m-i+1];
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			x=i;
			i=1000000;
		}
	}int u,o;
	u=x%n;
	if(u==0){
	o=x/n;
	u=n;
	}
	else o=(x-u)/n+1;
	if(o%2==0)u=n-u+1;
	cout<<o<<" "<<u;
}
