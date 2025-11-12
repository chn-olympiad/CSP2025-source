#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,a[105],x;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	x=a[1];
	for(int i=2;i<=n*m;i++) cin>>a[i];
	sort(a+1,a+n*m+1);
	int l=1,h=0;
	for(int i=n*m;i>=1;i--)
	{
		if(h+1>n)l++,h=1;
		else h++;
		if(a[i]==x)
		{
			if(l%2==1)cout<<l<<" "<<h;
			else cout<<l<<" "<<n-h+1;
		}
	}
	return 0;
} 
