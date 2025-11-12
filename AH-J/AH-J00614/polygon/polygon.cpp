#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[5005];
int ans;
bool b[105][105][105];
void dfs(int i,int cnt,int len,int maxa){
    if(cnt<3){
        dfs(i+1,cnt+1,len+a[i+1],max(maxa,a[i+1]));
    }
//    if(len==3){
//        cout<<"是三角形"<<len<<' '<<maxa<<endl;
//    }
//    cout<<maxa<<endl;
    if(len>2*maxa){
        if(b[len][cnt][maxa]){
            return;
        }
//        cout<<len<<' '<<cnt<<' '<<maxa<<endl;
        ans++;
        ans%=998244353;
        b[len][cnt][maxa]=true;
        if(len==0) ans--;
        return;
    }
    if(i>n){
        return;
    }
    dfs(i+1,cnt+1,len+a[i+1],max(maxa,a[i+1]));
    dfs(i+1,cnt,len,maxa);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n-2;i++){
        if(a[i+2]<a[i]+a[i+1])
            ans++;
    }
    dfs(0,0,0,0);
    cout<<ans;
    return 0;
}

