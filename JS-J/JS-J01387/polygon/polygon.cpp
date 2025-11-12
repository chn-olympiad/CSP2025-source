#include<bits/stdc++.h>
using namespace std;
int n;
int a[5000+10];
long long ans=0;
int maxn=0;
int sum=0;
int m=0;
void dfs(int p){
    if(p>n){
        return;
    }
    m++;
    sum+=a[p];
    maxn=max(maxn,a[p]);
    if(sum>maxn*2&&m>=3){
        ans++;
    }
    dfs(p+1);
    dfs(p+2);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    /*
    iint maxn=0;
    int m=0;
    int sum=0;
    for(int i=1;<=n;i++){
        maxn=0;m=0;sum=0;
        for(int j=i;j<=n;j++){
            m++;
            sum+=a[j];
            maxn=max(a[j],maxn);
            if(m>=3&&sum>maxn*2){
                ans++;
            }
        }
    }
    cout<<ans;
    */
    dfs(1);
    cout<<ans;
	return 0;
}


