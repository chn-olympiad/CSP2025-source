#include<bits/stdc++.h>
using namespace std;
int n,a[100000];
long long ans,res;
void dfs(int k,int s){
    for(int i=k;i<=n;i++){
        s+=a[i];
        if(s>a[i]*2)ans++;
        dfs(i+1,s);
        s-=a[i];
    }
}
int main(){
   // freopen("polygon.in","r",stdin);
   // freopen("polygon.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
sort(a+1,a+1+n);
dfs(1,0);
cout<<ans;




return 0;
}
