#include<bits/stdc++.h>
using namespace std;
const int N=10005;
int n,m,a[N],r;
bool cmp(int x,int y)
{
	return x>y;
}
void sc(int x)
{
	int l,h;
	if(x%n==0)
		l=x/n;
	else
		l=x/n+1;
	
	
	if(l%2)
		h=(x%n==0?n:x%n);
	else
		h=(x%n==0?1:n-x%n+1);
	
	cout<<l<<" "<<h<<"\n";
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++)
		if(a[i]==r)
			sc(i);
	return 0;
}
