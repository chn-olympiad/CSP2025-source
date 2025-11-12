#include<bits/stdc++.h>
using namespace std;
int a[105],n,m,s,pos,c,r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	s=a[1];
	sort(a+1,a+n*m+1);
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			pos=n*m-i+1;
			break;
		}
	}
	if(pos%n==0)c=pos/n;
	else c=pos/n+1;
	if(c%2==1)r=(pos-1)%n+1;
	else r=n-(pos-1)%n;
	cout<<c<<' '<<r<<endl;
	return 0;
}
