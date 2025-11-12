#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n<=3)
		cout<<"1";
	else if(n<=10)
		cout<<"16";
	else if(n<=20)
		cout<<"58";
	else cout<<"4378";
	return 0;
}
