#include<bits/stdc++.h>
using namespace std;
int n,num=0,a[5000],b[5000],m,c[5000],x,ans,nun,g;
int o(int i){
    if(i==0)return false;
    if(x>n) c[ans+1]=ans+1,c[x-1]++;
    if(c[x-1]==n)c[x-1]=ans-1,c[x-2]++;
    b[m]=a[c[x]];
    m++;
    o(i-1);
}
int v(int i,int g){
    ans=i;
    for(g=n;g>0;g--){
        x=i;
        o(i);
        for(int j=0;j<i;j++)
            nun+=b[i];
        sort(b,b+i);
        if(nun>b[i-1]*2)num++;
    }
}
int main(){
    freopen("polygin.in","r",stdin);
    freopen("polygin.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
        c[i]=i;
    for(int i=3;i<n;i++){
        for(int i=n-2;i>0;i++)
            g+=i;
        v(i,g);
    }
    cout<<num;
    return 0;
}
