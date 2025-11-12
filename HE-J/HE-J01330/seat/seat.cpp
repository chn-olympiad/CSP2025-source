#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,pai=0,h=0,s=0;
	cin>>n>>m;
	int ji[n*m+1];
	for(int i=1;i<=n*m;i++)
		cin>>ji[i];
	for(int i=2;i<=n*m;i++)
	{
		if(ji[i]>ji[1])
			pai+=1;
	}
	if(pai%n>0)
	s=pai/n+1;
	else
	s=pai/n;
	if(s%2>0)
	h=pai%n+1;
	else
	h=n-pai%n+1;
	if(h>n)
	{
		h=h%n;
		s=s+1;
	}
	cout<<s<<" "<<h;
	return 0;
}
