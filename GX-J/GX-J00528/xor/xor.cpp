#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("xor.in","r",stdin.in);
    freopen("xor.out","w",stdin.out);
    int n,k;
    cin>>n>>k;
    int a[n];
    int s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]==k)
        {
            s++;
            a[i]=-1;
        }
    }

    for(int i=0;i<n;i++)
    {
        if(a[i]==-1||a[i+1]==-1)
            continue;
        int r=a[i];
        int j=i+1;
        while(a[j]!=-1&&j<n){
            r|=a[j];
            j++;
            if(r==k)
            {
                s++;
                i=j;
                r=a[i];
                j=i+1;
            }
        }

    }
    cout<<s;
    return 0;
}
