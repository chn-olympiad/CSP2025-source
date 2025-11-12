#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int T;
int n,ans;
int c[4];
struct node{int Sa[4];}a[N];
void dfs(int num,int sum){
    //cout<<sum<<endl;
    //for(int i=1;i<=3;i++)cout<<c[i]<<" ";cout<<"\n";
    if(num==n+1){
        ans=max(ans,sum);
        return;
    }
    for(int i=1;i<=3;i++){
        if(c[i]>=n/2)continue;
        c[i]++;
        dfs(num+1,sum+a[num].Sa[i]);
        c[i]--;
    }
}
int main()
{
    freopen("Club1","r",stdin);
    //freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].Sa[1]>>a[i].Sa[2]>>a[i].Sa[3];
        }
        dfs(1,0);
        cout<<ans<<endl;
        for(int i=1;i<=n;i++){
            a[i].Sa[1]=a[i].Sa[2]=a[i].Sa[3]=0;
        }
        c[1]=c[2]=c[3]=0;
        ans=0;
    }
    return 0;
}
