#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	char a[10010];
	int x=m*n;
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		sort(a+1,a+1+x);
		cout<<a+1<<a+1+x;;
	}
	return 0;
}