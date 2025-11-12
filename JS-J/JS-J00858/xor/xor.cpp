#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500009],f[500009],suit[500009];
bool is_one=0,zero_one=0;

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1)is_one=1;
        if(a[i]!=1&&a[i]!=0)zero_one=1;
    }
    if(k==0&&!is_one){
        cout<<n/2;
        return 0;
    }else if((k==0||k==1)&&!zero_one){
        int ans=0;
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0)ans++;
                if(a[i]==1&&a[i+1]==1)ans++,i++;
            }
            cout<<ans;
            return 0;
        }else{
            for(int i=1;i<=n;i++){
                if(a[i]==1)ans++;
            }
            cout<<ans;
            return 0;
        }
    }else{
        for(int i=1;i<=n;i++){
            int j=i,sum=a[i];
            while(j<=n&&sum!=k){
                j++;
                sum^=a[j];
            }
            suit[j]=i;
        }
        f[0]=0;
        for(int i=1;i<=n;i++){
            f[i]=f[i-1];
            if(suit[i]){
                f[i]=max(f[i],f[suit[i]-1]+1);
            }
        }
        //for(int i=1;i<n;i++)cout<<f[i]<<" ";
        cout<<f[n];
        //cout<<suit[2];
        return 0;
    }
    return 0;
}
