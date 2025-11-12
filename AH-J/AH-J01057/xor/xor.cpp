#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[500005];
long long sum[500005];
bool vis[500005];
long long cnt=0;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=(sum[i-1]^a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(abs(sum[j]-sum[i-1])==k){
                bool flag=false;
                for(int k=i;k<=j;k++) if(vis[k]){flag=true;break;}
                if(!flag){
                cnt++;
                for(int k=i;k<=j;k++) vis[k]=1;
                }

            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
}
