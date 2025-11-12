#include <bits/stdc++.h>
using namespace std;
long long c[1000005];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int h=0;
    long long b=1;
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            c[a[i]-'0']++;
            h=max(a[i]-'0',h);
        }
    }
    for(int i=h;i>=0;i--)
    {
        for(int j=1;j<=c[i];j++)
        {
            cout<<i;
        }
    }
    return 0;
}
