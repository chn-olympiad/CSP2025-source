#include<bits/stdc++.h>
using namespace std;
int n,cnt,a[5005],pre[5005],c[5005];
bool f;
void dfs(int x,int sum,int l){
    if(sum>a[x]){
        cnt++;
    }
    if(l==a[x-1]){
        return;
    }
    for(int i=l+1;i<x;i++){
        dfs(x,sum+a[i],i);
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            f=1;
        }
    }
    if(!f){
        int sum=0,x=0;
        for(int i=2;i<n;i++){
            x=x*2+i-1;
            sum+=x;
        }
        cout<<sum<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=3;i<=n;i++){
        if(pre[i-1]<=a[i]) continue;
        int num=0;
        while(pre[i-1]-pre[num]<=a[i]) num++;
        dfs(i,0,num);
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
