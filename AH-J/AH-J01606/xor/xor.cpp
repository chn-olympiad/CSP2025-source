#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
   freopen("xor.in","r",stdin);
   freopen("xor.out","w",stdout);

    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }

    if(n<5000)
    {
        vector<int> adj(n);
        int sum=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++) adj[j]=0;

            for(int j=i;j<n;j++)
            {
                int f=0;
                adj[j-i]=a[j];
                if(adj[j-i]==k) f=1;
                for(int z=0;z<j-i;z++)
                {
                    int c=adj[z]^a[j];
                    adj[z]=c;
                    if(adj[z]==k){
                        f=1;
                        break;
                    }
                }
                if(f==1)
                {
                    i=j;
                    sum++;
                    break;
                }
            }

        }
        cout<<sum<<endl;
    }

    else
    {
        for(int i=0;i<n;i++) if(a[i]!=0 and a[i]!=1) break;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==k) sum++;
        }

        cout<<sum<<endl;
    }
    return 0;
}
