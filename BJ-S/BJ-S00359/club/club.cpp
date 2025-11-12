#include<bits/stdc++.h>
using namespace std;
int a[100005];
int b[100005];
int c[100005];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int s,q,d;
            cin>>a[i]>>b[i]>>c[i];
            int w=max(max(a[i],b[i]),c[i]);
            if(w==a[i])
            {
                s++;
            }
            if(w==b[i])
            {
                q++;
            }
            if(w==c[i])
            {
                d++;
            }
            cnt+=w;
        }
        cout<<cnt<<endl;
    }

    return 0;
}
