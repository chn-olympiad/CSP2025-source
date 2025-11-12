#include<bits/stdc++.h>
using namespace std;
int a[5005];
int n;
int main(){
	int t=0;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	int i;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long s=0,ma=-1;
	for(i=1;i<=n;i++)
	{
		s+=a[i];
		if(a[i]>ma)
		{
			ma=a[i];
		}
	}
	if(s>2*ma)
	{
		t++;
	}
	cout<<t;
	return 0;
} 
