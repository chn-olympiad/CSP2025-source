#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int t,n;
struct clb{
    int a,b,c;
}a[N];

int dfs(int i,int ans,int l1,int l2,int l3){

    if(l1>n/2)return -1;
    if(l2>n/2)return -1;
    if(l3>n/2)return -1;
    if(i>n)return ans;

    int ans1=dfs(i+1,ans+a[i].a,l1+1,l2,l3);
    int ans2=dfs(i+1,ans+a[i].b,l1,l2+1,l3);
    int ans3=dfs(i+1,ans+a[i].c,l1,l2,l3+1);

    return max(max(ans1,ans2),ans3);



}


signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){

        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
        }

        cout<<dfs(1,0,0,0,0)<<endl;
    }


return 0;
}
