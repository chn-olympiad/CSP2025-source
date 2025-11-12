#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
struct baack{
    int value;
    int biggest;
};
int n,a[5005],vis[5005],nownum;
/*baack dfs(int num,int biggest){
    int ans;
    baack sum;
    if(num==0){
        baack b;
        b.value=0;
        b.biggest=biggest;
        return b;
    }
    for(int i=0;i<n;i++){
        if(vis[i]==1){
            continue;
        }
        vis[i]=1;
        sum=dfs(n--,max(biggest,a[i]));
        sum.value+=a[i];
        vis[i]=0;
        ans=max(ans,sum.value);
    }
    if(num==nownum){

    }
    return ans;
}*/
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n==3){
        int tmp=-1,tongji=0;
        for(int i=0;i<n;i++){
            tmp=max(tmp,a[i]);
            tongji+=a[i];
        }
        cout<<(2*tmp<tongji)<<endl;
        return 0;
    }
    /*
    for(int i=3;i<=n;i++){//count the S of this polygon
        nownum=i;
        dfs(i,0);
    }*/
    return 0;
}
