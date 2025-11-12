#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005],x=0;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>a;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='0' && a[i]<='9')
        {
            b[x]=a[i]-'0';
            x++;
        }
    }
    sort(b,b+x);
    for(int i=x-1;i>=0;i--)
    {
        cout<<b[i];
    }
    return 0;
}
