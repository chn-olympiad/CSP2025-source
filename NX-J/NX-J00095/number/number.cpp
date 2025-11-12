#include<bits/stdc++.h>
using namespace std;
string n;
long long a[100000001];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,n);
	string x;
	long long sum=0;
	long long l=n.size();
	for(long long i=0;i<l;i++)
	{
		if(n[i]>='0' && n[i]<='9')
		{
			a[i]=n[i];
			sum++;
		}
	} 
	for(long long i=0;i<sum;i++)
	{
		if(a[i]>48) a[i]=a[i]-48;
		if(a[i]==48) a[i]=1;
		sort(a,a+sum);
	}
	for(long long i=sum-1;i>=0;i--)
	{
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
