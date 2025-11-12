#include <bits/stdc++.h>
using namespace std;
int a[10000];
int n
bool judge(int sum,int big){
    if(sum>big*2)
    return 1;
    else
    return 0;
}
int choose(int num,int s,int sum,int da){
    if(num==0){
        if(judge(sum,da)){
            return 1;
        }
        return 0;
    }
    int ans=0;
    for(int i=s+1;i<=n-num+1;i++){
        sum+=a[i];
        da=max(da,a[i]);
        ans+=choose(num-1,i,sum,da);
        sum-=a[i];
    }return ans;
}
int main(){
    freopen ("polygon.in","r",stdin);
    freopen ("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int tot=0;
    for(int k=3;k<=n;k++){
        tot+=choose(k,0,0,-1);
    }
    cout<<tot;
    return 0;
}
//HB-J00723 shizouyu 04-03 2025.11.01  ⨌
