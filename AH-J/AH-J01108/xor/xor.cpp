#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
//Root
long long aa,bb,fA=1;
//A
long long f[500005],ff,cnt1;
//B
long long sum[500005],m;
struct st{
    long long l,r;
}x[500005];
//ALL
void tryA(){
    cout<<n/2;
}
void tryB(){
    if(k==1){
        cout<<cnt1;
    }else{
        long long cnt2=n-cnt1;
        for(int i=1;i<=n;i++){
            if(a[i]==1&&a[i-1]==1&&f[i-1]!=1){
                f[i]=1;
                cnt2++;
            }
        }
        cout<<cnt2;
    }
}
bool cmp(const st &x,const st &y){
    return x.r<y.r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n;
    cin>>k;
    if(k<=1){
        ff=1;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            fA=0;
        }
        if(a[i]!=0&&a[i]!=1){
            ff=0;
        }else if(a[i]==1){
            cnt1++;
        }
        sum[i]=sum[i-1]^a[i];
    }
    if(k==0&&fA){
        tryA();
        return 0;
    }
    if(ff){
        tryB();
        return 0;
    }
    for(int ll=1;ll<=n;ll++){
        for(int rr=ll;rr<=n;rr++){
            if((sum[rr]^sum[ll-1])==k){
                x[++m].l=ll;
                x[m].r=rr;
                break;
            }
        }
    }
    sort(x+1,x+1+m,cmp);
    long long lr=x[1].r,cnt=1;
    for(int i=2;i<=m;i++){
        if(x[i].l>lr){
            cnt++;
            lr=x[i].r;
        }
    }
    cout<<cnt;
    return 0;
}
