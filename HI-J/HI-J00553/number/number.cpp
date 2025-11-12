#include<bits/stdc++.h>
using namespace std;
string s;
int n,h,j;
string a[1000005];
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			a[j]=s[i];
			h+=1;
			j+=1;
		}
	}
	cout<<h<<endl;
	sort(a,a+h);
	for(int i=h;i>=0;i--)
	{
		cout<<a[i];
	}
	return 0;
}
