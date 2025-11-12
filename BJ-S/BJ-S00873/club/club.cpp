#include<bits/stdc++.h>
using namespace std;
long long t,n,ans,a[111111],b[111111],c[111111],ca[111111],cb[111111],cc[111111],ch[111111];
bool cmp(long long x,long long y){return ch[x]>ch[y];}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        ans=0;
        memset(ca,0,sizeof(ca));
        memset(cb,0,sizeof(cb));
        memset(cc,0,sizeof(cc));
        memset(ch,0,sizeof(ch));
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            if(a[i]>=b[i]&&a[i]>=c[i]){
                ans+=a[i];
                ch[i]=a[i]-max(b[i],c[i]);
                ca[++ca[0]]=i;
            }
            else if(b[i]>=a[i]&&b[i]>=c[i]){
                ans+=b[i];
                ch[i]=b[i]-max(a[i],c[i]);
                cb[++cb[0]]=i;
            }
            else{
                ans+=c[i];
                ch[i]=c[i]-max(a[i],b[i]);
                cc[++cc[0]]=i;
            }
        }
        if(cb[0]>n/2) for(int i=cb[0];i>=0;i--) ca[i]=cb[i];
        if(cc[0]>n/2) for(int i=cc[0];i>=0;i--) ca[i]=cc[i];
        if(ca[0]>n/2){
            sort(ca+1,ca+ca[0]+1,cmp);
            for(;ca[0]>n/2;) ans-=ch[ca[ca[0]]],ca[0]--;
        }cout<<ans<<endl;
    }return 0;
}
