#include<bits/stdc++.h>
using namespace std;
long long n,a[100050][4],ans=0;
long long cha[100005];
long long dp[100005];
long long fu[5];
long long ma[100005];
void dfs(long long d,long long sum,long long xuan1,long long xuan2,long long xuan3){
    if(d>n){
        ans=max(ans,sum);
        //cout<<xuan1<<" "<<xuan2<<" "<<xuan3<<"\n";
        return;
    }
    if((xuan1+1)<=n/2){
        dfs(d+1,sum+a[d][0],xuan1+1,xuan2,xuan3);
    }
    if((xuan2+1)<=n/2){
        dfs(d+1,sum+a[d][1],xuan1,xuan2+1,xuan3);
    }
    if((xuan3+1)<=n/2){
        dfs(d+1,sum+a[d][2],xuan1,xuan2,xuan3+1);
    }
}
bool cmp(long long aa,long long bb){
    return aa>bb;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;cin>>t;
    while(t--){
    cin>>n;
    ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        fu[1]=a[i][0];fu[2]=a[i][1];fu[3]=a[i][2];
        sort(fu+1,fu+4,cmp);
        cha[i]=fu[1]-fu[2];
    }
    if(n<=10&&0){
        dfs(1,0,0,0,0);
        cout<<ans<<"\n";
    }
    else{
            long long ans=0;
        long long maxx=0;
        long long p=0;
        for(int i=1;i<=n;i++){
                maxx=-9999;
            for(int j=0;j<=2;j++){
                if(a[i][j]>maxx){
                    maxx=a[i][j];p=j;
                }
            }
    ans+=maxx;
            dp[i]=p;
        }
        long long aaa[4];
        memset(aaa,0,sizeof(aaa));
        for(int i=1;i<=n;i++){
            aaa[dp[i]]++;
        }
        long long kk=-1;
        long long k=0;
        for(int i=0;i<=2;i++){
                //cout<<aaa[i]<<" * ";
            if(aaa[i]>n/2){
                kk=i;
            }
        }
        if(kk==-1){
                //cout<<"rghsghnghyu";
            cout<<ans<<"\n";
        }
        else{

            for(int i=1;i<=n;i++){
                    //cout<<cha[i]<<" "<<dp[i]<<"\n";
                if(dp[i]==kk){
                    k++;
                    ma[k]=cha[i];
                }
            }//cout<<k<<" ";
            sort(ma+1,ma+1+k);
            for(int i=1;i<=k-n/2;i++){
                ans-=ma[i];
                //cout<<ma[i]<<"\n";
            }
            cout<<ans<<"\n";
        }
    }
    }
    return 0;
}
