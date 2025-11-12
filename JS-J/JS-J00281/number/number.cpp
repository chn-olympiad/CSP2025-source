#include <bits/stdc++.h>
using namespace std;
int a[1000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
     	a[s[i]]++;
    }
    for(int i=9;i>=0;i--)
    {
     	for(int j=1;j<=a[i+48];j++)
        {
            cout<<i;
        }
	}
    return 0;
}
