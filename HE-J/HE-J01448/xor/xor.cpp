#include<bits/stdc++.h>//#Shang4Shan3Ruo6Shui4
using namespace std;
int x,y,a[100],n=0;
int main()
{
	peropen("number.in","r",stdin);
	peropen("number.out","w",stdout);
	cin>>x>>y;
	for(int i=1;i<=x;i++)
	{
		cin>>a[i];
		n=n+a[i];
	}
	cout<<n/x<<endl;
	return 0;
}
