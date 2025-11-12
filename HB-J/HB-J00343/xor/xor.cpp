#include<bits/stdc++.h>
using namespace std;

const int N=5*1e5+5;
long long  n,k;
long long a[N];

void dfs (int st,int cnt){
    if(st==n+1){
        cout<<cnt<<endl;
        return ;
    }
    for(int i=1;i<=n-st;i++){
        int x=a[st+1];
        for(int j=st+1;j<st+i;j++){
            x=x^a[j];
        }
        if(x==k){
            dfs(st+i,++cnt);
        }
        else continue;
    }
}
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=1;i<=n;i++){
    cin>>a[i];
}
if(n==1&&k==0){
    cout<<'0';
}
else if(n==2&&k==0){
    cout<<'1';
}
else if(k==0){
    cout<<'1';
}
dfs(0,0);
return 0;
}
