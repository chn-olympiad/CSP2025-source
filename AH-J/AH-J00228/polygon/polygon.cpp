#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[5005],ans;
int n;
void f(int k,int sum,int cnt){
    if(cnt>=3&&sum>a[k-1]*2){
        ans++;
    }
    if(k==1+n)    return ;
    f(k+1,sum+a[k],cnt+1);
    f(k+1,sum,cnt);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    f(1,0,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
