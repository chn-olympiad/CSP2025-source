#include <bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
}a[100001];
string a[200001][2];
int n,ans;
void dfs(int step,int tmp,int a1,int b1,int c1){
    if(step==n+1){
        ans=max(ans,tmp);
        return;
    }
    if(a1<n/2){
        dfs(step+1,tmp+a[step].a,a1+1,b1,c1);
    }
    if(b1<n/2){
        dfs(step+1,tmp+a[step].b,a1,b1+1,c1);
    }
    if(c1<n/2){
        dfs(step+1,tmp+a[step].c,a1,b1,c1+1);
    }
    return;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;++i){
        cin>>a[i][0]>>a[i][1];
    }
    for(int i=1;i<=q;++i){
        sring s,p;
        cin>>s>>p;
        cout<<n*n<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
