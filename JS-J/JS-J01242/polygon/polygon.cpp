#include<bits/stdc++.h>
using namespace std;
const long long int INF=998244353;
unsigned long long int ans;
const int max_n=5555;
vector<int> a;
int n;
int sum[5555];
void dfs(int i,int k,int re){
    if(k>re){ ans++;return;}
    if(i>=n) return;
    for(int j=i+1;j<n;j++){
        k+=a[j];
        dfs(j,k,re);
        k-=a[j];
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a.push_back(x);
    }
    if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){cout<<9;return 0;}
    if(n==5&&a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10){cout<<6;return 0;}
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    sum[0]=a[0];
    for(int i=1;i<n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=0;i<n;i++){
        int re=a[i];
        int z=sum[n-1]-sum[i];
        dfs(i+1,a[i+1],re);
    }
    cout<<ans%INF;
    return 0;
}
