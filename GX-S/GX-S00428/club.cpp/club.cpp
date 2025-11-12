
#include<bits/stdc++.h>
using namespace std;
int main()
{int t;
cin>>t;
for(int n=1;n<=t;n++)
{int a[10000];
    int b[10000];
    int c[10000];
    int jia,jib,jic;
    for(int i=1;i<=n;i++)
        {cin>>a[i];
        cin>>b[i];
        cin>>c[i];

        }
for(int k=1;k<=n-1;k++)
        {for(int l=1;l<=k-l;l++)
            {
            if(a[l]>a[l+1]) swap(a[l],a[l+1]);
            if(b[l]>b[l+1]) swap(b[l],b[l+1]);
            if(c[l]>c[l+1]) swap(c[l],c[l+1]);
            }
        }
        for(int i=n;i>n/2;i--)
        {jia=jia+a[i];
        jib=jib+b[i];
        jic=jic+c[i];
        }
        int man;
        man=max(jia,jib);
        int ans;
        ans=max(man,jic);
        cout<<ans;
        }

return 0;
}
