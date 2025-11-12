#include<bits/stdc++.h>
using namespace std;
typedef long long  LL;
LL n,k,a[500005],ans,f=0;
bool flag[500005];
LL xr(LL x,LL y){
    LL idx=0,ans1=0;
    do{
        int b1=x%2,b2=y%2;
        if(b1!=b2) ans1+=pow(2,idx++);
        x=(x-b1)/2,y=(y-b2)/2;
    }while(x!=0||y!=0);
    return ans1;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>1) f=1;
    }
    if(k==1||k==0&&f==0){
        if(k==0){
            for(int i=1;i<=n;i++){
                if(a[i]==0) ans++;
                else if(a[i]==1&&a[i+1]==1) ans++,i++;
            }
        }else if(k==1){
            for(int i=1;i<=n;i++){
                if(a[i]==1) ans++;
                else if(a[i]==0&&a[i+1]==1) ans++,i++;
            }
        }
    }else {
        LL l=1,r=1,sum=a[1],x=1,p=0;
        for(int i=1;i<=n;i++)
            if(a[i]==k){
                flag[i]==true;
                ans++,p++;
            }
        while(l<n&&r<=n){
            if(flag[l]==1&&l==r) l++,r++,sum=a[++x];
            else{
                ++r;
                if(flag[r]==1){
                    l=r+1,r=l,sum=a[r+1];
                    continue ;
                }else{
                    sum=xr(sum,a[r]);
                    if(sum==k){
                        ans++;
                        sum=a[r+1];
                        l=r+1;
                        r=l;
                    }
                }

            }
        }
        ans=ans-p;
    }
    cout<<ans;
    return 0;
}
