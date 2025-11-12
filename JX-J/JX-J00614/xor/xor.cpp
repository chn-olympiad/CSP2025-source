#include<bits/stdc++.h>
using namespace std;
int n,k,ai=0,aj=0;
long long ans=0;
int a[500005];
int sc(int ii,int jj){
    if(ii<ai)return 0;
    int num=0;
    while(num!=k){
        num=0;
        for(int i=ii;i<=jj;i++){
            num=num^a[i];
        }
        //cout<<num<<endl;
        if(num==k){
            ai=ii;
            aj=jj;
            //cout<<"aaa"<<ii<<' '<<jj<<endl;
            ans++;
            return 1;
        }
        int b,c;
        if(ii<jj)b=sc(ii+1,jj);
        if(jj<n)c=sc(ii,jj+1);
        //return b+c;
        return 0;
    }
    return 0;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    //cout<<(int)pow(2,20);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    long long cnt=0;
    int ii=0,jj=0;
    while(jj<=n){
        ii=aj+1;
        jj=ii;
        int d=sc(ii,jj);
        //cout<<'a'<<d<<endl;
        cnt+=d;
     //   cnt+=sc(ii,jj);
    }
    //cout<<cnt<<'\n';
    cout<<ans<<'\n';
    //cout<<0%2;
    return 0;
}
