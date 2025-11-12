#include<bits/stdc++.h>
using namespace std;
bool flag1=1,flag2=1;
int n,k,flag2s=0,cnt=0,ans,point,point2,rans=0;
map<int,int> a,ll,rr;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            flag1=0;
        }
        if(a[i]>1||a[i]<0){
            flag2=0;
        }
        if(flag2&&a[i]==1){
            flag2s++;
        }
    }
    if(flag1){
        if(k==1){
            cout<<n;
        }
        else{
            cout<<0;
        }
    }
    else if(flag2){
        if(k==1){
            cout<<flag2s;
        }
        else{
            cout<<n-flag2s;
        }
    }
    else{
        for(int l=1;l<=n;l++){
            for(int r=l;r<=n;r++){
                ans=a[l];
                for(int i=l+1;i<=r;i++){
                    ans=ans xor a[i];
                }
                if(ans==k){
                    cnt++;
                    ll[cnt]=l;
                    rr[cnt]=r;
                }
            }
        }
        point=-1;
        point2=-1;
        for(int i=1;i<=cnt;i++){
            if(rr[i]>point&&ll[i]>point2){
                point=rr[i];
                point2=ll[i];
                rans++;
            }
        }
        cout<<rans;
    }
    return 0;
}
