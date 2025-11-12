#include<bits/stdc++.h>
using namespace std;
const int N=5000+5;
int a[N],n,k,ans=0,b[N];
bool cor(int x){
    int num=0,maxx=-1;
    for(int i=1;i<=x;i++){
        num+=a[b[i]];
        if(a[b[i]]>maxx){
            maxx=a[b[i]];
        }
    }
    if(num>2*maxx){
        return true;
    }else{
        return false;
    }
}
void dfs(int h,int dep,int tlth){

    if(dep==tlth+1){
        if(cor(dep-1)==true){
            ans++;
        }
        return;
    }
    int head=h+1;
    if(head>n){
        return;
    }
    for(int head=h+1;head<=n;head++){
        b[dep]=head;
        dfs(head,dep+1,tlth);
        b[dep]=0;
    }

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int lth=3;lth<=n;lth++){
        dfs(0,1,lth);
        b[1]=1;
    }


    cout<<ans%998244353<<endl;
    return 0;
}
