#include <bits/stdc++.h>
using namespace std;
long long k,n,a[200005],s1,s2,xx;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==k)
        {
            s2++;
        }
    }
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=n-i+1;j++)
        {
            s1=0;
            for(xx=j;xx<=i+j-1;xx++)
            {
                s1=(s1^a[xx]);
            }
            if(s1==k)
            {
                s2++;
            }
        }
    }
    cout<<s2;
    return 0;
}
