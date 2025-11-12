#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int num=a.size();
	int b[num];int s=0;
	for(int i=0;i<num;i++)
	{
		if((int)a[i]-48<10&&(int)a[i]-48>=0)
		{
			b[s]=(int)a[i]-48;
			s++;
		}
	}
	sort(b,b+s);
	for(int i=s-1;i>=0;i--)
	{
		cout<<b[i];
	}
	return 0;
}
