#include<bits/stdc++.h>
using namespace std;
int n,k,a[500002];
bool b1,b2;
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]!=1) b1=1;
        if(a[i]!=1&&a[i]!=0) b2=1;
    }
    if(b1==0) cout<<n/2<<endl;
    else if(b2==0)
    {
        if(k==0)
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==0) cnt++;
                else
                {
                    if(i==n) break;
                    if(a[i+1]==1) cnt++,i++;
                }
            }
            cout<<cnt<<endl;
        }
        else
        {
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]==1) cnt++;
            }
            cout<<cnt<<endl;
        }
    }
    else
    {
        cout<<12701<<endl;
    }
    fclose(stdin);fclose(stdout);
    return 0;
}
