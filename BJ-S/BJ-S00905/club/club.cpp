#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
struct ll{
long long v1,v2,v3;
}a[maxn];
int n=0,t=0;
bool cmp(ll a,ll b){
    return a.v2<=b.v2;
}

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        long long sum=0,g1=0,g2=0,g3=0;
        cin>>n;
        for(int i=0;i<n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            a[i].v3=i;
            if(x>=y){
                if(x>=z){
                    sum+=x;g1++;a[i].v3=1;
                    if(y>=z){a[i].v2=x-y;}
                    else{a[i].v2=x-z;}
                }
            else{a[i].v2=z-x;sum+=z;g3++;a[i].v3=3;}
            }
            else{
                if(y>=z){sum+=y;g2++;a[i].v3=2;
                    if(x>=z){a[i].v2=y-x;}
                    else{;a[i].v2=y-z;}
                }
            else{a[i].v2=z-y;sum+=z;g3++;a[i].v3=3;}
        }
    }
    if(g1>(n/2)){
        sort(a,a+n,cmp);
        int q=0;
        for(int i=0;i<n;i++)
        {
        if(g1==n/2)break;
        if(a[i].v3==1)
        {sum-=a[i].v2;
        g1--;}

        }
    }
    else if(g2>(n/2)){
        sort(a,a+n,cmp);
        int q=0;
        for(int i=0;i<n;i++)
        {
        if(g2==n/2)break;
        if(a[i].v3==2)
        {sum-=a[i].v2;g2--;}}
    }
    else if(g3>(n/2)){
        sort(a,a+n,cmp);
        int q=0;
        for(int i=0;i<n;i++)
        {
        if(g3==n/2)break;
        if(a[i].v3==3)
        {sum-=a[i].v2;g3--;}
        }
    }
    cout<<sum<<endl;
    }
    return 0;
}
