#include<bits/stdc++.h>
using namespace std;
int main(){

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    long long s,g;
    cin>>s;
    long long a[1000000];
    for(long long i=1;s>0;i++)
    {
        a[i]=s%10;
        s/=10;
        g=i;
    }
    sort(a,a+g+1);
    for(long long i=g;i>=1;i--)
    {
        cout<<a[i];
    }


    return 0;
}
