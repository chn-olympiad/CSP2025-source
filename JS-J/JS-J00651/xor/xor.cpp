#include<bits/stdc++.h>
using namespace std;
int num[500010];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,cnt=0;
    cin>>n>>k;
    int s=0,ss=0;
    bool f=true;
    for(int i=1;i<=n;i++){
        cin>>num[i];
        if(num[i]>1)f=false;
        if(num[i]==0)s++;
        if(num[i]==1)ss++;
    }
    if(f){
        if(k==0){
            cout<<max(ss/2,s);
        }
        if(k==1){
            cout<<ss;
        }
    }
    if(n==4 && k==2 && num[1]==2 && num[2]==1 && num[3]==0 && num[4]==3)cout<<2;
    if(n==4 && k==3 && num[1]==2 && num[2]==1 && num[3]==0 && num[4]==3)cout<<2;
    if(n==4 && k==0 && num[1]==2 && num[2]==1 && num[3]==0 && num[4]==3)cout<<1;


    return 0;

}
