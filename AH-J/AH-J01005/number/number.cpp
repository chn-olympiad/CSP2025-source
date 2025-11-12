#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r","stdin");
	freopen("number.out","w","stdout");
	char a[1000000],q='9';
	int b[1000000],l=0;
	cin>>a;
	int d=strlen(a);
	for(int i=1;i<=d;i++)
	{
		if(a[i]%1==0)
		{
			b[i]=a[i]-'0';
			q=min(q,a[i]);
			l++;
		}
	}
	sort(b+1,b+l+1,greater<int>());
	for(int j=1;j<l;j++)
		cout<<b[j];
	cout<<q-'0';
	return 0;
}
