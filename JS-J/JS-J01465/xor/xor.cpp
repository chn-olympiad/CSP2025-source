#include<bits/stdc++.h>
using namespace std;
long long n,k,a[100005],m=0;
int xorr (int x,int y){
    int x2[25],y2[25];
    memset(x2,0,sizeof(x2));
    memset(y2,0,sizeof(y2));
    int i=1,xx,yy;
    while(x!=0){
        x2[i]=x%2;
        x=x/2;
        i++;
    }
    xx=i-1;
    i=1;
    while(y!=0){
        y2[i]=y%2;
        y=y/2;
        i++;
    }
    yy=i-1;
    int t,ans=0;
    t=max(xx,yy);
    for(i=1;i<=t;i++){
        if(x2[i]!=y2[i]){
            ans+=pow(2,i-1);
        }
    }
    return ans;
}
void find (int l,int r,int t){
    if(l>r){
        if(t-1>m) m=t-1;
        return ;
    }
    for(int i=l;i<=r;i++){
        int x;
        if(l==i) x=a[i];
        else{
            x=a[l];
            for(int v=l+1;v<=i;v++){
                x=xorr(x,a[v]);
            }
        }
        if(x==k){
            find(i+1,r,t+1);
        }
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    find(1,n,1);
    cout<<m;
    return 0;
}
