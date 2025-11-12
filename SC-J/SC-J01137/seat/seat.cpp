#include<bits/stdc++.h>
using namespace std;
int n,m,ans,x,y,z;
struct node{
	int z,f;
}a[1000];
bool cmp(node b,node c){
	return b.z>c.z;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n*m;i++) cin>>a[i].z;
	a[1].f=1;
	sort(a+1,a+n*m+1,cmp);
	for (int i=1;i<=n*m;i++)
		if(a[i].f==1) ans=i;
	if(ans%n==0)y=ans/n;
	else y=ans/n+1;
	if(ans%n==0) z=n;
	else z=ans%n;
	if(y%2!=0) x=z;
	else x=n+1-(z);
	cout<<y<<" "<<x;
	return 0;
}