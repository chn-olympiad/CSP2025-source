#include<bits/stdc++.h>
using namespace std;
struct sd{
    int sa,id;
}a[4];
bool cmp(sd a,sd b){
    return a.sa>b.sa;
}
int t,n,p[200005],cnt[4],f[200005],ans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        memset(cnt,0,sizeof(cnt));
        memset(p,0,sizeof(p));
        ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[j].sa;
                a[j].id=j;
            }
            sort(a+1,a+4,cmp);
            ans+=a[1].sa;
            cnt[a[1].id]++;
            f[i]=a[1].id;
            p[i]=a[1].sa-a[2].sa;
        }
        int flag=0;
        for(int i=1;i<=3;i++){
            if(cnt[i]>n/2) flag=i;
        }
        if(!flag) cout<<ans<<endl;
        else{
            int c=0;
            for(int i=1;i<=n;i++){
                if(f[i]==flag) p[++c]=p[i];
            }
            sort(p+1,p+1+c);
            for(int i=1;i<=cnt[flag]-n/2;i++){
                ans-=p[i];
                //cout<<p[i]<<" ";
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
