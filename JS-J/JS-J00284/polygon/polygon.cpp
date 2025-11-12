#include<iostream>
using namespace std;
int n,a[5005],b[5005],ans;
bool judge(){
    int s=0,m=0;
    for(int i=1;i<=n;i++){
        if(b[i]){
            s+=a[i];
            m=max(m,a[i]);
        }
    }
    return (s>2*m);
}
void dfs(int index,int sn){
    if(!sn){
        if(judge()){
            ans++;
        }
        return ;
    }
    for(int i=index+1;i<=n;i++){
        b[i]=1;
        dfs(i,sn-1);
        b[i]=0;
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    if(n<3){
        cout<<0;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=2;j<n;j++){
            b[i]=1;
            dfs(i,j);
            b[i]=0;
        }
    }
    cout<<ans;
    return 0;
}