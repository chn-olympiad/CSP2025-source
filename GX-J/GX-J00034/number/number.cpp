
#include<bits/stdc++.h>
using namespace std;
int a[100005];
string s;
int main(){
	freopen("number.in","w",stdin);
	freopen("number.out","r",stdout);
	cin>>s;
	int c=s.length();
	for (int i=0;i<c;i++)
	{
		if (s[i]>='0' && s[i]<='9') 
		{
			a[s[i]-'0']++;
		}
	}
	for (int i=9;i>=0;i--)
	{
		if (a[i]>=1)
		for (int j=0;j<a[i];j++)
		{
			cout<<i;
		}
	}
	return 0;
}
