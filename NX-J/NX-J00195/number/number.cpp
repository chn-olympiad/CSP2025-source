#include<bits/stdc++.h>
using namespace std;
long long cnt[10];
string sz[10]={"0","1","2","3","4","5","6","7","8","9"};
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a,s;
    cin>>a;
    for(int i=0;i<=a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            cnt[int(a[i])-48]++;
        }
    }
    for(int i=9;i>=0;i--)
    {
        int i1=cnt[i];
        while (i1>0)
        {
            i1--;
            s+=sz[i];
        }
    }
    cout<<s;

    return 0;
}
