#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,k,mx=0x3f3f3f3f,maxn,p;
int a[500005];
int sum[500005];
int f[5005][5005];
int find(int l,int r){
    bool t=(l<=5004&&r<=5004);
    if(t&&f[l][r]!=mx)return f[l][r];
    int ans=((sum[r]^sum[l-1])==k);
    for(int i=l;i^r;i++){
        ans=max(ans,find(l,i)+find(i+1,r));
    }if(t)return f[l][r]=ans;
    else return ans;
}int find2(int l,int r){
    if(f[l][r]!=mx)return f[l][r];
    int ans=((sum[r]^sum[l-1])==k);
    for(int i=l;i^r;i++){
        ans=max(ans,find2(l,i)+find2(i+1,r));
    }return f[l][r]=ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    bool flag=(n>5004);
    memset(f,0x3f,sizeof(f));
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        f[i][i]=(a[i]==k);
        sum[i]=(sum[i-1]^a[i]);
        maxn=max(maxn,a[i]);
    }if(k==1&&maxn<=1){
        int cnt=0;
        for(int i=1;i<=n;i++){
            cnt+=a[i];
        }cout<<cnt;
    }else if(flag){
        cout<<find(1,n);
    }else{
        cout<<find2(1,n);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
