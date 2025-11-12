#include<bits/stdc++.h>
using namespace std;
long long n,a[5005];
long long sumw;
void dfs(long long dep,long long sum,long long  cnt){
    for(long long i=dep;i<n;i++){
        if(cnt>=2){
            if(sum+a[i]>2*a[i]){
                sumw++;
                sumw%=998244353;
            }
        }
        dfs(i+1,sum+a[i],cnt+1);
    }
}
int main(){
  freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
    cin>>n;
    for(long long i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    dfs(0,0,0);

    cout<<sumw%998244353;
    return 0;
}
