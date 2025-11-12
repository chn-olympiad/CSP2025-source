#include<bits/stdc++.h>
using namespace std;
struct jy{
    int maxn,mx,mid;
}k[200005];
bool cmp(jy a,jy b){
    return a.mx<b.mx;
}
int T;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        int n,d[5]={},f[5][200005]={},w,a[10]={},b[10]={},c[10]={};
        long long ans=0;
        cin>>n;
        if(n==2){
            for(int i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i];
            int t1=a[1]+b[2];
            int t2=a[1]+c[2];
            int t3=b[1]+a[2];
            int t4=b[1]+c[2];
            int t5=c[1]+a[2];
            int t6=c[1]+b[2];
            t1=max(t1,t2);
            t3=max(t3,t4);
            t5=max(t5,t6);
            cout<<max(t1,max(t3,t5))<<endl;
        }
        else {
            int m=n/2;
            for(int i=1;i<=n;i++){
                int a,b,c;
                cin>>a>>b>>c;
                k[i].maxn=max(a,max(b,c));
                int minn=min(a,min(b,c));
                k[i].mid=a+b+c-k[i].maxn-minn;
                k[i].mx=k[i].maxn-k[i].mid;
                ans+=k[i].maxn;
                if(k[i].maxn==a){
                    d[1]++;
                    f[1][d[1]]=k[i].maxn;
                }
                else if(k[i].maxn==b){
                    d[2]++;
                    f[2][d[2]]=k[i].maxn;
                }
                else {
                    d[3]++;
                    f[3][d[3]]=k[i].maxn;
                }
            }
            int dd=max(d[1],max(d[2],d[3]));
            if(dd==d[1])w=1;
            else if(dd==d[2])w=2;
            else w=3;
            sort(k+1,k+n+1,cmp);
            int p=1;
            int l=dd;
            while(dd>m){
                for(int i=1;i<=l;i++){
                    if(k[p].maxn==f[w][i]){
                        ans-=k[p].maxn;
                        ans+=k[p].mid;
                        dd--;
                    }
                }
                p++;
            }
            cout<<ans<<endl;
        }
    }
return 0;
}
