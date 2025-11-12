#include<bits/stdc++.h>
using namespace std;
struct st{
    char idx;
    int p;
}mus[100005];
bool cmp(st x,st y){
    return x.p<y.p;
}
int T,n,a[100005],b[100005],c[100005],sa,sb,sc,ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio();
    cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--){
        sa=sb=sc=ans=0;
        cin>>n;
        int k=n/2;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            int mx=max(a[i],max(b[i],c[i]));
            if(a[i]==mx){
                sa++;
                mus[i].idx='a';
                mus[i].p=min(a[i]-b[i],a[i]-c[i]);
            }
            else if(b[i]==mx){
                sb++;
                mus[i].idx='b';
                mus[i].p=min(b[i]-a[i],b[i]-c[i]);
            }
            else {
                sc++;
                mus[i].idx='c';
                mus[i].p=min(c[i]-a[i],c[i]-b[i]);
            }
            ans+=mx;
        }
        sort(mus+1,mus+n+1,cmp);
        if(sa>k){
            for(int i=1;i<=n;i++){
                if(sa<=k)break;
                if(mus[i].idx=='a'){
                    ans-=mus[i].p;
                    sa--;
                }
            }
        }
        else if(sb>k){
            for(int i=1;i<=n;i++){
                if(sb<=k)break;
                if(mus[i].idx=='b'){
                    ans-=mus[i].p;
                    sb--;
                }
            }
        }
        else if(sc>k){
            for(int i=1;i<=n;i++){
                if(sc<=k)break;
                if(mus[i].idx=='c'){
                    ans-=mus[i].p;
                    sc--;
                }
            }
        }
        cout<<ans<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
