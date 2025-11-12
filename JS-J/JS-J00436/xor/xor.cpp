#include<bits/stdc++.h>
using namespace std;
int a[500005];
int s(int x,int y){
    int ans=0;
    for(int i=x;i<=y;i++){
        ans=ans ^ a[i];
    }
    return ans;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int z=0,x=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]==1) z++;
        else if(a[i]==0) x++;
    }
    if(k==1){
        cout<<z;
    }
    if(k==0){
        cout<<x;
    }
    else{
        int xx=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(i<=xx) break;
            for(int j=i;j<=n;j++){
                int sum=s(i,j);
                if(sum==k){
                    cnt++;
                    xx=j;
                    continue;
                }
            }
        }
        cout<<cnt;
    }
    return 0;
}

