#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin>>s;
	long long n[10]={};
	for(int i=0;i<s.size();i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            n[s[i]-'0']++;
        }
    }
    for(int i=9;i>=0;i--)
        for(int j=0;j<n[i];j++)
            cout<<i;
	return 0;
}
