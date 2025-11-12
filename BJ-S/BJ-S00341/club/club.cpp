#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long t,n,a[100011][4];
long long tot,ans=-1;
int e[100011];
int f[100011];
int b[101];
int en[4],spb,spc,spp;
int st,iis,wwa;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int qt=1;qt<=t;qt++){
        spb=0;
        spc=0;
        tot=0;
        en[1]=0;
        en[2]=0;
        en[3]=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][2]!=0){
                spb++;
            }
            if(a[i][3]!=0){
                spc++;
            }
            e[i]=0;
            if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
                e[i]=1;
                en[1]++;
            }else if(a[i][2]>a[i][1]&&a[i][2]>a[i][3]){
                e[i]=2;
                en[2]++;
            }else if(a[i][3]>a[i][1]&&a[i][3]>a[i][2]){
                e[i]=3;
                en[3]++;
            }
            tot=tot+max(a[i][1],max(a[i][2],a[i][3]));
        }
        if(spb==0){
            ans=0;
            for(int i=1;i<=n;i++){
                f[i]=a[i][1];
            }
            sort(f+1,f+n+1);
            spp=n;
            while(spp>(n+1)/2){
                ans=ans+f[spp];
                spp--;
            }
            cout<<ans<<endl;
            continue;
        }
        if(en[1]<=n/2&&en[2]<=n/2&&en[3]<=n/2){
            cout<<tot<<endl;
            continue;
        }
        if(n<=15){
            ans=0;
            int s=pow(3,n);
            for(int i=0;i<s;i++){
                en[1]=0;
                en[2]=0;
                en[3]=0;
                tot=0;
                iis=i;
                b[0]=0;
                wwa=n;
                while(wwa>0){
                    wwa--;
                    b[0]++;
                    st=iis%3+1;
                    b[b[0]]=st;
                    iis=iis/3;
                    tot=tot+a[b[0]][st];
                    en[st]++;
                }
                if(en[1]<=n/2&&en[2]<=n/2&&en[3]<=n/2){
                    ans=max(ans,tot);
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
