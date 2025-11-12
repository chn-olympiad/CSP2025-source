#include<bits/stdc++.h>
using namespace std;
int a[100000];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin>>s;
    int k;
    for(int i=0;i<=s.size()-1;i++)
    {
        int t=s[i]-'0';
        k++;
    }
    sort(a+1,a+k);
    for(int i=k-1;i>=k;i--)
    {
        cout<<ka[i]
    }
    return 0;
}
