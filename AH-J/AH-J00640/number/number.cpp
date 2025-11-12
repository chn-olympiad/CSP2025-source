#include<bits/stdc++.h>
using namespace std;
int x[10];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	string s;
	cin>>s;
	for(int i=0;i<=s.size()-1;i++)
	{
		if('0'<=s[i]&&s[i]<='9')
		{
			x[int(s[i])-48]++;
		}
	}
	for(int i=9;i>=0;i--)
	{
		while(x[i]--)
		{
			cout<<i;
		}
	}
    return 0;
}
