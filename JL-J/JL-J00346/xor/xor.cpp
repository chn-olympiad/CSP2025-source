#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct node{
    int qz,zqd,yqd;
}qj[N];
long long n,k,a[N],ii,P,qz[N],ans,dqy,zc,Pb,dp[N],gx[N];
bool cmp(node x,node y){
    return x.yqd<y.yqd;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    if(k>1){
        Pb=1;
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        if(a[i]!=1&&a[i]!=0){
            Pb=1;
        }
    }
    if(Pb==0&&n>100){
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    ans++;
                }
            }
            cout<<ans;
            return 0;
        }
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    ans++;
                }
            }
            for(int i=1;i<=n;i++){
                if(a[i]==1&&P==0){
                    zc++;
                    P=1;
                }
                else if(a[i]==1&&P==1){
                    zc++;
                }
                else if(P==1&&a[i]==0){
                    P=0;
                    ans=ans+zc-1;
                    zc=0;
                }
            }
            cout<<ans;
            return 0;
        }
    }
    if(Pb==1&&n<=100){
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(i==j){
                    zc=a[i];
                }
                else{
                    zc=a[i];
                    for(int k=i+1;k<=j;k++){
                        zc=zc^a[k];
                    }
                }
                if(zc==k){
                    ii++;
                    if(i==j){
                        qj[ii].qz=zc;
                        qj[ii].zqd=i;
                        qj[ii].yqd=j;
                    }
                    else{
                        qj[ii].zqd=i;
                        qj[ii].yqd=j;
                        qj[ii].qz=zc;
                    }
                }
            }
        }
        sort(qj+1,qj+ii+1,cmp);
        dqy=qj[1].yqd;
        ans=1;
        for(int i=2;i<=ii;i++){
            if(qj[i].zqd>dqy){
                ans++;
                dqy=qj[i].yqd;
            }
        }
        cout<<ans;
        return 0;
    }
    if(Pb==1&&n>100){
        for(int i=1;i<=n;i++){
            dp[i]=max(dp[i-1],dp[i]);
            if(a[i]==k){
                dp[i]=dp[i-1]+1;
            }
            else if(i!=n){
                zc=a[i];
                for(int j=i+1;j<=n;j++){
                    zc=zc^a[j];
                    if(zc==k){
                        dp[j]=dp[i-1]+1;
                        gx[j]=1;
                        break;
                    }
                }
            }
        }
        cout<<dp[n];
        return 0;
    }
    return 0;
}
