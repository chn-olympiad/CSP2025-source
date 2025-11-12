#include<bits/stdc++.h>
using namespace std;
int a,b,c,asum,bsum,csum;
int sumab[100005],sumac[100005],sumba[100005],sumbc[100005],sumca[100005],sumcb[100005],ans;
int cnta=1,cntb=1,cntc=1;
bool flaga[100005],flagb[100005],flagc[100005],flag[100005],za,zb,zc,first;
int main(){
    freopen("club","r",stdin);
    freopen("club","w",stdout);
    int t,n,a1[100005],b1[100005],c1[100005];
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a1[i]>>b1[i]>>c1[i];
            if(a1[i]>=b1[i]&&a1[i]>=c1[i]){
                sumab[i]=a1[i]-b1[i];
                sumac[i]=a1[i]-c1[i];
                if(a<(n/2)){
                    flaga[cnta]=1;
                    cnta++;
                    a++;
                }else{
                    flag[i]=0;
                   for(int j=1;j<=cnta;j++){
                        if(a1[i]<a1[j]&&sumab[i]<sumab[j]&&sumac[i]<sumac[j]){
                            flag[i]=1;
                            if(sumab[i]<sumac[i]&&b<(n/2)){
                                b++;
                                flagb[i]=1;
                                break;
                            }else{
                                c++;
                                flagc[i]=1;
                                break;
                            }
                        }
                   }
                   if(flag[i]==0){
                        first=0;
                        int Min=(1<<30);
                        for(int j=1;j<=cnta;j++){
                            if(sumab[j]<sumac[j]&&sumab[j]<Min&&b<(n/2)){
                                if(first==0){
                                    first=1;
                                    za=1;
                                    Min=sumab[j];
                                    b++;
                                    a--;
                                    flagb[j]=1;
                                    flaga[j]=0;
                                }else if(za==1){
                                    Min=sumab[j];
                                    flagb[j]=1;
                                    flaga[j]=0;
                                    flagb[j-1]=0;
                                    flaga[j-1]=1;
                                }else{
                                    Min=sumab[j];
                                    za=1;
                                    c--;
                                    b++;
                                    flaga[j]=1;
                                    flagb[j]=0;
                                    flagc[j-1]=0;
                                    flagb[j-1]=1;
                                }
                            }else{
                                if(sumbc[j]<Min){
                                    if(first==0){
                                    first=1;
                                    za=0;
                                    Min=sumbc[j];
                                    c++;
                                    a--;
                                    flagc[j]=1;
                                    flagb[j]=0;
                                }else if(za==0){
                                    Min=sumbc[j];
                                    flagc[j]=1;
                                    flagb[j]=0;
                                    flagc[j-1]=0;
                                    flagb[j-1]=1;
                                }else{
                                    Min=sumbc[j];
                                    za=0;
                                    b--;
                                    c++;
                                    flagc[j]=1;
                                    flaga[j]=0;
                                    flagb[j-1]=0;
                                    flaga[j-1]=1;
                                }
                                }
                            }
                        }
                        flagb[cntb]=1;
                        cntb++;
                        b++;
                   }
                }
            }else if(b1[i]>=a1[i]&&b1[i]>=c1[i]){
                sumba[i]=b1[i]-a1[i];
                sumbc[i]=b1[i]-c1[i];
                if(b<(n/2)){
                    flagb[cntb]=1;
                    cntb++;
                    b++;
                }else{
                    flag[i]=0;
                   for(int j=1;j<=cntb;j++){
                        if(b1[i]<b1[j]&&sumba[i]<sumba[j]&&sumbc[i]<sumbc[j]){
                            flag[i]=1;
                            if(sumba[i]<sumbc[i]&&a<(n/2)){
                                a++;
                                flaga[i]=1;
                                break;
                            }else{
                                c++;
                                flagc[i]=1;
                                break;
                            }
                        }
                   }
                   if(flag[i]==0){
                        first=0;
                        int Min=(1<<30);
                        for(int j=1;j<=cntb;j++){
                            if(sumba[j]<sumbc[j]&&sumba[j]<Min&&a<(n/2)){
                                if(first==0){
                                    first=1;
                                    za=1;
                                    Min=sumba[j];
                                    a++;
                                    b--;
                                    flaga[j]=1;
                                    flagb[j]=0;
                                }else if(za==1){
                                    Min=sumba[j];
                                    flaga[j]=1;
                                    flagb[j]=0;
                                    flaga[j-1]=0;
                                    flagb[j-1]=1;
                                }else{
                                    Min=sumba[j];
                                    za=1;
                                    c--;
                                    a++;
                                    flaga[j]=1;
                                    flagb[j]=0;
                                    flagc[j-1]=0;
                                    flagb[j-1]=1;
                                }
                            }else{
                                if(sumbc[j]<Min){
                                    if(first==0){
                                    first=1;
                                    za=0;
                                    Min=sumbc[j];
                                    c++;
                                    b--;
                                    flagc[j]=1;
                                    flagb[j]=0;
                                }else if(za==0){
                                    Min=sumbc[j];
                                    flagc[j]=1;
                                    flagb[j]=0;
                                    flagc[j-1]=0;
                                    flagb[j-1]=1;
                                }else{
                                    Min=sumbc[j];
                                    za=0;
                                    a--;
                                    c++;
                                    flagc[j]=1;
                                    flagb[j]=0;
                                    flaga[j-1]=0;
                                    flagb[j-1]=1;
                                }
                                }
                            }
                        }
                        flagb[cntb]=1;
                        cntb++;
                        b++;
                   }
                }
            }else{
                sumca[i]=c1[i]-a1[i];
                sumcb[i]=c1[i]-b1[i];
                if(c<(n/2)){
                    flagc[i]=1;
                    c++;
                }
            }
        }
        for(int i=1;i<=cnta;i++){
        if(flaga[cnta]==1){
            ans+=a1[i];
        }
    }
    for(int i=1;i<=cntb;i++){
        if(flagb[cntb]==1){
            ans+=b1[i];
        }
    }
    for(int i=1;i<=cntc;i++){
        if(flagc[cntc]==1){
            ans+=c1[i];
        }
    }
    cout<<ans<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
