#include<iostream>
using namespace std;
long long n,k,a[1005],b[1005][1005],c[1000005][2],ci=1,sa=1;
int num;
bool t(int ta,int tb){
    return !(c[ta][1]>=c[tb][0]);
}
void dfs(int index,int now){
    if(c[index][1]==n){
        num=max(num,now);
        return ;
    }
    for(int i=index+1;i<ci;i++){
        if(t(index,i)){
            dfs(i,now+1);
        }
    }
    num=max(num,now);
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]!=1){
            sa=0;
        }
    }
    if(sa&&k==0){
        cout<<n/2;
        return 0;
    }
    for(int i=1;i<=n;i++){
        b[i][i]=a[i];
        if(a[i]==k){
            c[ci][0]=i,c[ci][1]=i;
            ci++;
        }
        for(int j=i+1;j<=n;j++){
            b[i][j]=b[i][j-1]^a[j];
            if(b[i][j]==k){
                c[ci][0]=i,c[ci][1]=j;
                ci++;
            }
        }
    }
    for(int i=1;i<ci;i++){
       dfs(i,1);
    }
    cout<<num;
    return 0;
}