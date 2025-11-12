#include<bits/stdc++.h>
using namespace std;
int m=0,n=0,t=0;
long long a[5001],s;
int cmp(int x,int y){
    return x<y;
}
void dfs(int x,int k){
    bool b=(k<a[x]);
    s+=b;s%=998244353;
    if(x>=1){
        if(b)
            k=a[x]-1;
        for(int i=x-1;i>=0;i--){
            dfs(i,k-a[x]);
        }
    }
    else{
        return;
    }
}

int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp);
    for(int i=2;i<n;i++){
        dfs(i,2*a[i]);
    }
    cout<<s<<endl;
    return 0;
}
