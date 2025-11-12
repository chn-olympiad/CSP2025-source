#include <bits/stdc++.h>
using namespace std;

long long n,a[5010],s=0,yzy=1;

void dfs(int dq,int ss){
    yzy++;
for(int i=dq+1;i<=n;i++){
    if(ss+a[i]>a[i]*2){
        s++;
    }
    dfs(i,ss+a[i]);
}
yzy--;
}

int main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+n+1);
dfs(0,0);
cout<<s;

return 0;
}
