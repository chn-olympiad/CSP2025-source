#include<bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[100005];
int num;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n;
    cin>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]==k)
            num++;
    }
    for(int i=1;i<n;i++)
    {
        int st=0;
        st=(a[i]^a[i+1]);
        for(int j=i+2;j<=n+1;j++)
        {
            if(st==k)
            {
                num++;
            }
            st=(st^a[j]);
        }
    }
    cout<<num<<endl;
    return 0;
}
