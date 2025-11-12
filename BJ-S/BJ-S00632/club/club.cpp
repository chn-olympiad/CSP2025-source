#include<bits/stdc++.h>
using namespace std;
const int BS=1e5+5;
int A=0,B=0,C=0;
struct nm
{
    int a1,b1,c1;
    int a,b,c;
    int ot;
    int two;
    int maxi;
}maxn[BS];
bool cmp(nm x1,nm y1)
{
        return x1.ot < y1.ot;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    int n;
    cin>>T;
    while(T--)
    {
        cin>>n;
        int x = 0;
        for(int i=1;i<=n;i++)
        {
            maxn[i].maxi = -1e9;
        }
        A=0;
        B=0;
        C=0;
        for(int i=1;i<=n;i++)
        {
            cin>>maxn[i].a>>maxn[i].b>>maxn[i].c;
            int ai = max(maxn[i].a,maxn[i].b);
            if(ai == maxn[i].a){
               x = maxn[i].a;
            }
            else{
                x = maxn[i].b;
            }
            maxn[i].maxi = max(ai,maxn[i].c);
            if(maxn[i].maxi == ai){
                if(x == maxn[i].a){
                    A++;
                    maxn[i].a1=maxn[i].a;
                    maxn[i].two = max(maxn[i].b,maxn[i].c);
                    maxn[i].ot=maxn[i].a1-maxn[i].two;
                } else {
                    B++;
                    maxn[i].two = max(maxn[i].a,maxn[i].c);
                    maxn[i].b1=maxn[i].b;
                    maxn[i].ot=maxn[i].b1-maxn[i].two;
                }
            }
            else {
                C++;
                maxn[i].c1=maxn[i].c;
                maxn[i].two = max(maxn[i].b,maxn[i].a);
                maxn[i].ot=maxn[i].c1-maxn[i].two;
            }
        }
        sort(maxn+1,maxn+1+n,cmp);
        long long ans=0;
        int nn=n/2;
        for(int i=1;i<=n;i++)
        {
            ans+=maxn[i].maxi;
        }
        if(A>nn){
            for(int i=1;i<=n;i++)
            {
                if(A<=nn) break;
                if(maxn[i].a==maxn[i].a1){
                    ans-=maxn[i].ot;
                    A--;
                }
            }
        }
        else if(B>nn){
            for(int i=1;i<=n;i++)
            {
                if(B<=nn) break;
                if(maxn[i].b==maxn[i].b1){
                    ans-=maxn[i].ot;
                    B--;
                }
            }
        }
        else{
            for(int i=1;i<=n;i++)
            {
                if(C<=nn) break;
                if(maxn[i].c==maxn[i].c1){
                    ans-=maxn[i].ot;
                    C--;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
