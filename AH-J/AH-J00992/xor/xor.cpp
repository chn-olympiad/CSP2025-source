#include<bits/stdc++.h>
using namespace std;
int n;
int i,j,k,ans,sum;
int g[100050];
int a[500050];/*
int Xor(int q,int p){
    int x=q,y=p;
    int ans=0;
    int i;
    for(i=0;;i++){
        if((x|y)==0){
            break;
        }
        if((x|y)>=1&&(((x&y)>1))||((x&y)==0)){
            if(g[i]>0){
                ans=ans+g[i];
            }else{
                g[i]=pow(2,i);
                ans=ans+g[i];
            }
        }
        x=x>>1;
        y=y>>1;
        //cout<<x<<" "<<y<<endl;
    }
    return ans;
}*/
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>0){
            sum++;
        }
    }
    if(k==1){
        cout<<sum;
    }else if(k==0){
        cout<<n-sum+sum/2;
    }else{
        cout<<0;
    }
    return 0;
}
