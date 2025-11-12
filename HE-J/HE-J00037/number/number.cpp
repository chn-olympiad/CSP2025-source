#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
int a[1000005];
int l;
int i;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(i=0,l=0;i<s.size();i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			l++;
			a[l]=s[i]-'0';
		}
	}
	sort(a+1,a+l+1);
	for(i=l;i>=1;i--)
	{
		cout<<a[i];
	}
	return 0;
}
/*
fc C:\Users\Administrator\Desktop\HE-J00037\number\number.out C:\Users\Administrator\Desktop\HE-J00037\number\number4.ans
*/
