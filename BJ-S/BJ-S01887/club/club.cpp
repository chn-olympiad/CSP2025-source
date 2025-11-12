#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
struct stu{
    int a,b,c;
}d[N],a[N/2],b[N/2],c[N/2];
int n,q,m,idxa,idxb,idxc;
ll ans;
bool cmpa(stu x,stu y){
    return x.a<y.a;
}
bool cmpb(stu x,stu y){
    return x.b<y.b;
}
bool cmpc(stu x,stu y){
    return x.c<y.c;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>q;
    while(q--){
        cin>>n,m=n/2;
        ans=0,idxa=0,idxb=0,idxc=0;
        for(int i=0;i<n;i++)cin>>d[i].a>>d[i].b>>d[i].c;
        for(int i=0;i<n;i++){
            if(d[i].a>=d[i].b&&d[i].a>=d[i].c){
                a[idxa++]=d[i],ans+=d[i].a;
            }
            else if(d[i].b>=d[i].a&&d[i].b>=d[i].c){
                b[idxb++]=d[i],ans+=d[i].b;
            }
            else if(d[i].c>=d[i].a&&d[i].c>=d[i].b){
                c[idxc++]=d[i],ans+=d[i].c;
            }
        }
        if(n==2){
            int cnt1=max(d[0].a+d[1].b,d[0].a+d[1].c),cnt2=max(d[0].b+d[1].a,d[0].b+d[1].c),cnt3=max(d[0].c+d[1].b,d[0].c+d[1].a);
            ans=max(cnt1,max(cnt2,cnt3));
        }
        else if(idxa>m){
            sort(a,a+idxa,cmpa);
            int l=0;
            while(idxa-l>m){
                int y=max(a[l].b,a[l].c);
                ans+=y-a[l].a;
                l++;
            }
        }
        else if(idxb>m){
            sort(b,b+idxb,cmpb);
            int l=0;
            while(idxb-l>m){
                int y=max(b[l].a,b[l].c);
                ans+=y-b[l].b;
                l++;
            }
        }
        else if(idxc>m){
            sort(c,c+idxc,cmpc);
            int l=0;
            while(idxc-l>m){
                int y=max(c[l].a,c[l].b);
                ans+=y-c[l].c;
                l++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
