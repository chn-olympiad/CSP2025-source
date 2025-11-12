#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,se,ans,x,y;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	se=a[1];
	sort(a+1,a+1+n*m);
	for(int i=1;i<=n*m;i++)if(a[i]==se){
		ans=n*m-i+1;
		break;
	}
	x=ans/n+1,y=ans%n;
	if(y==0)x--,y=n;
	cout<<x<<" ";
	if(x%2==0)cout<<n-y+1;
	else cout<<y;
	return 0;
}

