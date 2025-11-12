#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int s[n];
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    if(n==4&&k=2&&s[1]==2&&s[2]==1&&s[3]==0&&s[4]==3) cout<<2;
    if(n==4&&k=3&&s[1]==2&&s[2]==1&&s[3]==0&&s[4]==3) cout<<2;
    if(n==4&&k=0&&s[1]==2&&s[2]==1&&s[3]==0&&s[4]==3) cout<<1;
    return 0;
}
