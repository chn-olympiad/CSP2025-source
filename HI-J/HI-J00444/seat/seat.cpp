#include<bits/stdc++.h> 
using namespace std;
int a[10086];
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m = 0,n = 0,cut = 1,num = 1,s = 0;
	cin>>m>>n;
	for(int i = 0;i<n*m;i++)
	{
		cin>>a[i];
		s = a[0];
	} 
	sort(a,a+n*m);
	for(int i = 0;i<n*m;i++)
	{
		if(n == 1&&a[i] == s)
		{
			cout<<num<<" "<<cut;
		}
		cut++;
	} 
	return 0;
}
