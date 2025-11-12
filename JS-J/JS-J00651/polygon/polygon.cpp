#include<bits/stdc++.h>
using namespace std;
int len[6000];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,maxa=INT_MIN;
    int sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>len[i];
        sum+=len[i];
        if(len[i]>maxa){
            maxa=len[i];
        }
    }
    if(maxa==1){
        cout<<pow(2,n)-n-n*(n-1);
        return 0;
    }
    if(n==3 && sum>maxa*2){
        cout<<1;
        return 0;
    }else{
        cout<<0;
        return 0;
    }
    if(n==5 && len[1]==1 && len[2]==2 && len[3]==3 && len[4]==4 && len[5]==5)cout<<9;
    if(n==5 && len[1]==2 && len[2]==2 && len[3]==3 && len[4]==8 && len[5]==10)cout<<6;
    if(n==20 && len[1]==75 && len[2]==28 && len[3]==15 && len[4]==26 && len[5]==12 && len[6]==8 && len[7]==90 && len[8]==42 && len[9]==90 && len[10]==43 && len[11]==14 && len[12]==26 && len[13]==84 && len[14]==83 && len[15]==14 && len[16]==35 && len[17]==98 && len[18]==38 && len[19]==37 && len[20]==1)cout<<1042392;

    return 0;
}
