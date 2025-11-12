#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k;
int a[N];
int op(int l,int r){
    int res=a[l];
    for(int i=l+1;i<=r;i++)
        res=res^a[i];
    return res;
}
int solve(int len){
    int res=0;
    for(int i=1;i<=n;i+=len){
        int j=i+len-1;
        if(op(i,j)==k)res++;
    }
    return res;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int ans=0;
    for(int len=1;len<=n;len++){
        ans=max(solve(len),ans);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
