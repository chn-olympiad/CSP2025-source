#include<bits/stdc++.h>
using namespace std;
char c[1000011];
char f(char a,char b)
{
    return a>b;
}
int main() {
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string a;
    int b;
    cin>>a;
    for(int i=0; i<a.size(); i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            c[b]=a[i];
            b++;
        }
    }
    sort(c,c+b,f);
    for(int i=0; i<b; i++)
    {
        cout<<c[i];
    }
}
