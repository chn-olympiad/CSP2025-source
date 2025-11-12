#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000010],k=1;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len1=a.size();
	for(int i=0;i<len1;i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b[k]=a[i]-'0';
			k++;
		}
	}
	sort(b+1,b+k);
	for(int i=k-1;i>=1;i--)
	cout<<b[i];
	cout<<endl;
	return 0;
}
