#include<bits/stdc++.h>
using namespace std;
int b[1000010];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	int n=0;
	cin>>a;
	for(int i=0;i<a.size();i++)
		if(a[i]>='0' && a[i]<='9')
		{
			n++;
			b[n]=a[i]-48;
		}
	sort(b+1,b+n+1);
	for(int i=n;i>=1;i--)
		printf("%d",b[i]);
	return 0;
}

