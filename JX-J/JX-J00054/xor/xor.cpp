#include<bits/stdc++.h>
using namespace std;
int n;
long long k,a[500005];
long long s[1005][1005];
long long cnt;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            s[i][j]=s[i][j-1]^a[j];
        }
    }
    int id=1;
    for(int i=1;i<=n;i=i+id){
        for(int j=i;j<=n;j++){
            if(s[i][j]==k){
                cnt++;
                id=j-i+1;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
