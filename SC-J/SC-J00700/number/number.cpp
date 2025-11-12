#include<bits/stdc++.h>
using namespace std;
//C:\Users\user\Downloads\cspj
string a;
string b;
bool cmp(char aa,char bb)
{
	return aa>bb;
}
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>a;
	
	for(int i=0;i<a.size();i++)
	{
		if(a[i]>='0'&&a[i]<='9')
		{
			b+=a[i];
		}
	}
	sort(b.begin(),b.end(),cmp);
	cout<<b;
	return 0;
}