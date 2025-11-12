#include<bits/stdc++.h>
using namespace std;
int a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	
	int x=a[1],k;
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--)
		if(a[i]==x)
		{
			k=n*m-i+1;
			break;
		}
	int p=k/n+1,q=k%n;
	if(q==0)
		p--,q=n;
	if(p%2==1)
		cout<<p<<" "<<q;
	else
		cout<<p<<" "<<n-q+1;
	return 0;
}
