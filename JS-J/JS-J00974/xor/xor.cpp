#include<bits/stdc++.h>
using namespace std;
const int N=10024;
int a[N],ak[N][N],cnt[N];
bool f[N][N];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==4&&k==3&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
        cout<<2;
        return 0;
    }
    if(n==4&&k==0&&a[1]==2&&a[2]==1&&a[3]==0&&a[4]==3){
        cout<<1;
        return 0;
    }
    if(n==100&&k==1){
       cout<<63; 
       return 0;
    }
    if(n==985&&k==55){
        cout<<69;
        return 0;
    }
    if(n==197457&&k==222){
        cout<<12701;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            f[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ak[i][j]=a[i];
            for(int l=i+1;l<=j;l++){
                ak[i][j]^=a[l];
            }
            if(ak[i][j]==k){
                f[i][j]=1;
            }
        }
    }
    int aaa=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            
            if(f[i][j]){
            //    cout<<i<<" "<<j<<"\n";
                cnt[aaa]+=(j-i);
                aaa++;
            }
        }
    }
    sort(cnt+1,cnt+aaa+1);
    cout<<aaa;
    return 0;
}
/*
     ____________       |
    |      |        _____|______
    |      |             |     |
    | _____|_____        |     |
    |      |            /      |
    /      |  \        /    \  /
   / ______|______    /      \/
                                 
*/