#include<bits/stdc++.h>
using namespace std;
string a;
int s[15],l;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	l=a.size();
	for(int i=0;i<l;i++)if('0'<=a[i]&&a[i]<='9')s[a[i]-'0']++;
	for(int i=9;i>=0;i--)for(int j=1;j<=s[i];j++)cout<<i;
}

