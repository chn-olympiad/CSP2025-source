#include <iostream>
using namespace std;

//累了，这次总分只有200分
int a[1001],a2[1001],n,k;
int result[1001][1001];
int qjxor(int l,int r){
    int ans=0;
    for(int i=l;i<=r;i++){
        ans^=a[i];
    }
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a2[i]=a[i];
        for(int j=1;j<=i;j++){
            result[j][i]=qjxor(j,i);
        }
    }
    int cnt=0;
    for(int l=1;l<=n;l++){
        for(int i=l;i<=n;i++){
            if(i==l-1) continue;
            if(result[l][i]==k||result[i][l]==k){
                cnt++;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}