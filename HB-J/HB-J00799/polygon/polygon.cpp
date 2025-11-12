#include<bits/stdc++.h>
using namespace std;
int sz[5010];
int n,ans=0;
int book[5010],bj[5010];
void judge(){
    int mid=0,maxz=-10,cnt=0;;
    for(int i=1;i<=n;i++){
        if(book[i]==1){
            mid+=sz[i];
            cnt++;
            maxz=max(maxz,sz[i]);
        }
    }if(mid>2*maxz&&cnt>=3){
        ans++;
        ans=ans%998244353;
    }return;
}void dfs(int k){
    if(k==n+1){
        /*for(int i=1;i<=n;i++){
            cout<<book[i]<<" ";
        }cout<<endl;*/
        judge();
        return;
    }
    book[k]=1;
    dfs(k+1);
    book[k]=0;
    dfs(k+1);
    return;
}void pf1(){
    dfs(1);
}int pr[1000];
int f=0;
void szs(){
    for(int i=2;i<=n;i++){
        int cnt=0;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                cnt++;
            }
        }if(cnt==0){
            pr[f++]=i;
        }
    }return;
}
void pj(int k,int c){
    int mid=1;
    while(k){
        if(k%pr[mid]==0){
            k/=pr[mid];
            if(c==1){bj[mid]++;}
            else{bj[mid]--;}
        }else{
            mid++;
        }
    }return;
}
int zhs(int n,int k){
    int zzj;
    for(int i=2;i<=k;i++){
        pj(i,1);        
    }for(int i=2;i<=n;i++){
        pj(i,0);
    }for(int i=2;i<=n-k;i++){
        pj(i,0);
    }for(int i=1;i<=k;i++){
        if(bj[k]==0){
            continue;
        }for(int j=1;j<=bj[k];j++){
            zzj%=998244353;
            zzj*=i;
        }
    }
    return zzj;
}
void pf2(){
    szs();
    for(int i=3;i<=n;i++){
        ans+=(zhs(i,n)%998244353);
        ans%=998244353;
    }return;
}int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>sz[i];
    }if(n<=20){
        pf1();

    }else{
        pf2();
    }cout<<ans;
    return 0;
}