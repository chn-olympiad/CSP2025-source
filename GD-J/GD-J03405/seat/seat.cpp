#include<bits/stdc++.h>
using namespace std;
int n,m,a[100005],t,k;
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	t=a[1];
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==t)k=i;
	int b=(k-1)/n+1;
	if(b%2==1)cout<<b<<" "<<(k-1)%n+1;
	else cout<<b<<" "<<n-(k-1)%n;
	return 0;
} 
