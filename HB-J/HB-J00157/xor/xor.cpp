/*
plan a:30 pts expected
plan b: pts expected

while(1){
    rp+=inf;
}
pls let me pass
i want 1st prize
plllllllllllllllllllsssssssssssssssssssss
*/
#include<iostream>
#include<cstdio>
using namespace std;
int n,k,a[500005],b[500005],cnt0,cnt1,cnt11;
bool special_a=1,special_b=1;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    //dp[i][j]=max(dp[i][j],dp[i][k]+dp[k+1][j]);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];

        if(a[i]!=1) special_a=0;
        if(a[i]!=1&&a[i]!=0) special_b=0;
        if(a[i]==1) cnt1++;
        if(a[i]==0) cnt0++;
        if(a[i]==1&&a[i-1]==1) cnt11++;

        b[i]=b[i-1]^a[i];
    }

    //plan a only for pianfening
    if(special_a) special_b=0;
    if(k==0&&special_a){
        cout<<n/2;
        return 0;
    }
    else if(k==0&&special_b){
        cout<<cnt0+cnt11;
        return 0;
    }
    else if(k==1&&special_b){
        cout<<cnt1;
        return 0;
    }

    //plan b also pianfen
    int cnt=0;
    for(int l=1,r=1;l<=n&&r<=n;r++){
        if(b[r]^b[l-1]==k){
            cnt++;
            l=r+1;
        }
    }
    cout<<cnt;
    return 0;
}
//touch to enter texts...
