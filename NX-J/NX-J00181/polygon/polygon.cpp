#include<bits/stdc++.h>
using namespace std;
int n,l[5000],cnt;
int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>l[i];
    }
    sort(l,l+n);
    for(int i=0; i<n; i++)
    {
        for(int j=n-1; j>=i; j--)
        {
            int b;
            for(int q=i; q<=j; q++)
            {
                b+=l[q];
            }
            if(b>2*l[j])
            {
                cnt++;
                cnt%=998244353;
            }
        }
    }
    cout<<cnt;
}
