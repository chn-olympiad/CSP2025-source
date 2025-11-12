#include<bits/stdc++.h>
using namespace std;
int jc(int a){
    int ans=1;
    for(int i=2;i<=a;i++){
        ans*=i;
    }
    return ans;
}
int cxy(int m,int n){
    int x=jc(m),y=jc(n);
    int z=jc(m-n);
    y*=z;
    return x/y;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int a,n[114514]={0},ans=0;
    cin>>a;
    for(int i=0;i<a;i++) scanf("%d",&n[i]);
    if(a==3){
        sort(n,n+a);
        if(n[0]+n[1]+n[2]>2*n[2]) cout<<1;
        else cout<<0;
    }
    else{
        for(int i=3;i<=a;i++){
            ans+=cxy(a,i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
