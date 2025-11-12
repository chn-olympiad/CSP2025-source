#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
    long long val[3];
    long long rev;
    long long mx;
}a[N];
bool cmp(node a,node b){
    return a.rev<b.rev;
}
long long x[3],cnt[3];
long long c[N];
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    long long T;
    cin>>T;
    while(T--){
        long long n,ans=0;
        for(int i=0;i<=2;i++) cnt[i]=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            long long maxn=0;
            for(int j=0;j<=2;j++){
                cin>>a[i].val[j];
                x[j]=a[i].val[j];
                maxn=max(maxn,a[i].val[j]);
            }
            a[i].mx=maxn;
            long k=x[0]+x[1]+x[2];
            long kmx=max(x[0],max(x[1],x[2]));
            long kmi=min(x[0],min(x[1],x[2]));
            a[i].rev=kmx-(k-kmx-kmi);
            for(int j=0;j<=2;j++){
                if(a[i].mx==a[i].val[j]){
                    cnt[j]++;
                    break;
                }
            }
            ans+=a[i].mx;
        }
        int b=-1;
        for(int i=0;i<=2;i++){
            if(cnt[i]>n/2){
                b=i;
                break;
            }
        }
        if(b==-1){
            cout<<ans<<endl;
            continue;
        }
        int cal=0;
        for(int i=1;i<=n;i++){
            bool flag=1;
            for(int j=0;j<=2;j++){
                if(a[i].val[b]<a[i].val[j]){
                    flag=0;
                    break;
                }
            }
            if(flag==0) continue;
            c[++cal]=a[i].rev;
        }
        sort(c+1,c+cal+1);
        for(int i=1;i<=cnt[b]-n/2;i++){
            ans-=c[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}