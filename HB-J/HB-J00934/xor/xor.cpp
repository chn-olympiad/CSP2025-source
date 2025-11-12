#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+10;
int a[maxn],b[maxn][maxn];//de4 i ge4 shu4 qian2 j ge4 shu4 yi4 huo4 he2
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(j==0){
                b[i][j]=a[i]^0;
            }
            else {
                b[i][j]=b[i-1][j-1]^a[i];
            }
        }
    }
    int x1=0,y1=0,ans=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++){
            if(b[i][j]==k && i-x1 >= j+y1){
                ans++;
                x1=i;
                y1=j;
            }
        }
    }
    cout<<ans;
    return 0;
}
