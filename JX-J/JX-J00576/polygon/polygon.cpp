#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5100];

void dfs(int m,int num,int tot){
    if(num>=3&&tot>a[m]*2){
        ans++;ans%=998244353;
        //cout<<num<< ' '<<tot<<endl;
    }
    if(m==n)return;
    //if(tot<=a[num]*2)return;
    for(int i=m+1;i<=n;i++)dfs(i,num+1,tot+a[i]);
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)dfs(i,1,a[i]);
    printf("%d",ans);
    return 0;
}
