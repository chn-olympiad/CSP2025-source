#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10,p=998244353;
int n,ans,flag;
int a[N],sum[N],qpow[N];
long long dfs(int ran,int num,int ned){
    if(sum[ran]<=ned) return 0;
    if(ned<=0){
        if(num==0){
            if(ned<0) return qpow[ran];
            else return qpow[ran]-1;
        }
        if(num==1) return qpow[ran]-1;
        if(num==2) return qpow[ran]-1-ran;
    }
    if(ran==2){
        int tmp=0;
        if(num<=0){
            if((a[1]+a[2])>ned) tmp++;
            if(a[2]>ned) tmp++;
            if(a[1]>ned) tmp++;
            if(0>ned) tmp++;
            return tmp;
        }
        if(num==1){
            if((a[1]+a[2])>ned) tmp++;
            if(a[2]>ned) tmp++;
            if(a[1]>ned) tmp++;
            return tmp;
        }
        if(num==2){
            if((a[1]+a[2])>ned) return 1;
            else return 0;
        }
    }
    return dfs(ran-1,num-1,ned-a[ran])+dfs(ran-1,num,ned);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n;qpow[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1) flag=1;
        qpow[i]=2*qpow[i-1];
        qpow[i]%=p;
    }
    if(flag){
       sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=3;i<=n;i++){
            ans+=dfs(i-1,2,a[i]);
            ans%=p;
        }
    }
    else{
        ans=qpow[n];
        ans--;ans-=n;
        ans-=n*(n-1)/2;
    }
    cout<<ans;
    return 0;
}
