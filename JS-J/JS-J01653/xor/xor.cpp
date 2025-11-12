#include<bits/stdc++.h>
using namespace std;
int yh(int x,int y){
    string bx="",by="",bz="";
    while(x||y){
        if(x){
            bx=char(x%2+'0')+bx;
            x=x/2;
        }
        if(y){
            by=char(y%2+'0')+by;
            y=y/2;
        }
    }
    if(bx=="")bx="0";
    if(by=="")by="0";

    while(bx.size()>by.size()){
        by="0"+by;
    }
    while(bx.size()<by.size()){
        bx="0"+bx;
    }
    for(int i=0;i<bx.size();i++){
        bz=bz+"0";
        if(bx[i]!=by[i]){
            bz[i]='1';
        }
        if(bx[i]==by[i]){
            bz[i]='0';
        }
    }

    int z=0;
    for(int i=0;i<bz.size();i++){
        z=z*2+int(bz[i]-'0');
    }
    return z;
}
int a[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int ans=0;
    int cnt=0;
    for(int s=1;s<=n;s++){
        cnt=0;
        for(int i=s;i<=n;i++){
            for(int j=i;j<=n;j++){
                int t=0;
                for(int k=i;k<=j;k++){
                    t=yh(t,a[k]);
                }
                if(t==k){
                    cnt++;
                    i=j+1;
                    j=i-1;
                }
            }
        }
        ans=max(ans,cnt);
    }
    cout<<ans;
    return 0;
}
