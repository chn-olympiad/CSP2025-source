#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000005],b[1000005],k=1;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[k]=int(s[i])-int('1')+1;
			k++;
		}
	}
	sort(a,a+k);
	for(int i=1;i<k;i++)
	{
		b[i]=a[k-i];
	}
	for(int i=1;i<k;i++)
	{
		cout<<b[i];
	}
	return 0;
} 