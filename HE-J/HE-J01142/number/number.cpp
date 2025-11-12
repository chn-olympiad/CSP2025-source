#include<bits/stdc++.h>
using namespace std;
int a[15];
long long sum;
int main()
{
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    string s;
    cin>>s;
    for(int i=0;i<s.length(); i++)
    {
        if(s[i]<60)
        {
            a[s[i]-48]++;
        }
    }
    for(int i=9; i>=0; i--)
    {
        while(a[i]--)
        {
            cout<<i;
        }
    }
    
}

