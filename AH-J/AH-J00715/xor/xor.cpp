#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],cnt;
struct ss{
    int st,ed;
}qj[10000005];
bool cmp(ss x,ss y){
    return x.ed<y.ed;
}
int dp[10000005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool tt=1;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]>1) tt=0;
    }
    if(tt==1&&k<=1&&n>1000){
        int cnt=0;
        if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1){
                    cnt++;
                }
            }
        }else{
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    cnt++;
                }else if(a[i-1]==1){
                    cnt++;
                    a[i-1]=a[i]=2;
                }
            }
        }
        cout<<cnt;
        return 0;
    }
    int t=0;
    for(int i=1;i<=n;i++){
        t^=a[i];
        int l=1,r=i,f=t;
        while(r!=n+1){
            if(f==k){
                cnt++;
                qj[cnt].st=l;
                qj[cnt].ed=r;
            }
            f^=a[l];
            l++;
            r++;
            f^=a[r];
        }
    }
    sort(qj+1,qj+cnt+1,cmp);
    qj[0].ed=0;
    dp[1]=1;
    for(int i=2;i<=cnt;i++){
        dp[i]=dp[i-1];
        for(int j=i-1;j>=0;j--){
            if(qj[i].st>qj[j].ed){
                dp[i]=max(dp[i],dp[j]+1);
                break;
            }
        }
    }
    cout<<dp[cnt];
    return 0;
}
