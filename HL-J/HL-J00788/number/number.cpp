#include<bits/stdc++.h>
using namespace std;
int b[100000000];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);

	string a;
	cin>>a;
	int n=a.size();
	int cnt=0;

	for(int i=0;i<n;i++)
	{
		if(a[i]>=48&&a[i]<59)
		{
			
			b[cnt]=a[i]-48;
			cnt++;
		}
		
	}
	sort(b,b+cnt);
	for(int i=cnt-1;i>=0;i--)
	{
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
