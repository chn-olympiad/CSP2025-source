#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int t,n,q,j[N][4];
int dp(int l,int a,int b,int c){
    if(l==0)
        return 0;
    int ans=0;
    if(a>0)
        ans=max(ans,dp(l-1,a-1,b,c)+j[l][1]);
    if(b>0)
        ans=max(ans,dp(l-1,a,b-1,c)+j[l][2]);
    if(c>0)
        ans=max(ans,dp(l-1,a,b,c-1)+j[l][3]);
    return ans;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        q=n/2;
        for(int i=1;i<=n;i++){
            cin>>j[i][1]>>j[i][2]>>j[i][3];
        }
        cout<<dp(n,q,q,q)<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
