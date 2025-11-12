#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int t,n,f=1,a[maxn][10],b[maxn]={0},c[maxn];
int sum=0,ans=0,d[maxn],cnt=0;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        sum=0;
        cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>a[i][j];
                if(b[i]<a[i][j]){
                    b[i]=a[i][j];
                    ans=j;
                }
            }
            c[ans]++;
            sum+=b[i];
        }
        for(int i=1;i<=n;i++){
            if(c[i]>n/2){
                ans=i;
                f=0;
            }
        }
        if(f==1) cout<<sum<<endl;
        else{
            for(int i=1;i<=n;i++){
                for(int j=2;j<=n;j++){
                    if(b[i]>b[j]){
                        d[i]=j;
                        swap(b[i],b[j]);
                    }
                }
            }
            for(int i=1;i<=c[ans]-(n/2);i++){
                sum-=b[i];
                if(ans==1) sum+=max(a[d[i]][2],a[d[i]][3]);
                if(ans==2) sum+=max(a[d[i]][1],a[d[i]][3]);
                else sum+=max(a[d[i]][1],a[d[i]][2]);
            }
            cnt=sum;
            for(int i=1;i<=n;i++){
                for(int j=2;j<=n;j++){
                    if(b[i]<b[j]){
                        d[i]=j;
                        swap(b[i],b[j]);
                    }
                }
            }
            for(int i=1;i<=c[ans]-(n/2);i++){
                sum-=b[i];
                if(ans==1) sum+=max(a[d[i]][2],a[d[i]][3]);
                if(ans==2) sum+=max(a[d[i]][1],a[d[i]][3]);
                else sum+=max(a[d[i]][1],a[d[i]][2]);
            }
            cout<<max(cnt,sum)<<endl;
        }
    }
    return 0;
}
