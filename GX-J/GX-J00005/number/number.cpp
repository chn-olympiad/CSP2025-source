#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    cin>>a;
    int n[a.size()+1],i=0;
    for(char x:a)
    {
        if(x>='0' and x<='9')
        {
            n[i]=(x-'0');
            i++;
        }
    }
    sort(n,n+i,greater<int>());
    for(int j=0;j<i;j++)
    {
        cout<<n[j];
    }
    return 0;
}
