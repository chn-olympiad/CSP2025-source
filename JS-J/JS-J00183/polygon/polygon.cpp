#include<bits/stdc++.h>
using namespace std;
int n,sum;
int a[5010];
int vis[5010];
int getsum(int x,int y){
    int ans=0;
    for(int i=x;i<=y;i++){
        ans+=a[i];
    }
    return ans;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=3;i--){
        for(int j=i-2;j>=1;j--){
            if(getsum(j,i-1)>i){
                sum+=j;
                continue;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
