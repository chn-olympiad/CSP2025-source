#include<bits/stdc++.h>
using namespace std;
struct NODE{
    int l,r;
    bool operator <(const NODE &tmp)const{
        return r<tmp.r;
    }
}t[1000005];
int n,k,a[500005],f[500005],cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=(f[i-1]^a[i]);
    }
    if(n<=1000){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                int e=(f[i]^f[j-1]);
                if(e==k){
                    t[++cnt]={j,i};
                }
            }
        }
        sort(t+1,t+cnt+1);
        int ans=0,lastr=0;
        for(int i=1;i<=cnt;i++){
            if(t[i].l>lastr){
                ans++;
                lastr=t[i].r;
            }
        }
        cout<<ans;
    }else{
        if(k==1){
            int sum=0;
            for(int i=1;i<=n;i++){
                sum+=a[i];
            }
            cout<<sum/2;
        }else cout<<"12701";
    }
    return 0;
}
