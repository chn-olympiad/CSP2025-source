#include<bits/stdc++.h>
using namespace std;
int i(int n,int m)
{
	int c;
	cin>>n>>m;
	int a[100];
	for(int i=0;i<n*m;i++)
	{
		cin>>a[i];
		c=a[0];
		if(a[i]<a[i+1])
		{
			swap(a[i],a[i+1]);
		}
		return a[i];
	}
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cout<<i(2,2);
	frclose(stdin);
	frclose(stdout);
	return 0;
}
