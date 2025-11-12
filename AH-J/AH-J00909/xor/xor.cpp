#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int s[500005];
struct T{
   int l,r;
}b[500005];
int in=1;
int sum;
int mx;
void dfs(int x,int y){
     int it=0;
     for(int i=1;i<in;i++){
        if(b[i].l<=y&&b[i].l>=x){
           it++;
        }else{
           sum++;
           dfs(b[i].l,b[i].r);
        }
     }
     if(it==in-1){
        mx=max(mx,sum);
        sum=0;
     }
     return ;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==k){
          b[in].l=b[in].r=i;
          in++;
        }
    }
    s[1]=a[1];
    for(int i=2;i<=n;i++){
        s[i]=s[i-1]^a[i];
    }
    for(int i=1;i<n;i++){
       for(int j=i+1;j<=n;j++){
          if(s[j]^s[i-1]==k){
             b[in].l=i;b[in].r=j;
             in++;
          }
       }
    }
    for(int i=1;i<in;i++){
        sum=0;
        dfs(b[i].l,b[i].r);
    }
    cout<<mx;
    return 0;
}
