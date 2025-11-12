#include<bits/stdc++.h>
using namespace std;

int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a;
long long  z[10]={0};
cin>>a;
for(int i=0;i<=a.length();i++)
{
    int b=a[i];
    if(b>=48&&b<=57)
    {
        z[b-48]++;
    }
}
for(int i=9;i>=0;i--)
    {
        for(long long j=0;j<z[i];j++){
            cout<<i;
        }
    }
return 0;
}
