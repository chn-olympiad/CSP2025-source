#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int a[N],d[N];
int n;
const long long MOD=998244353;
long long answer=0;

bool cmp(int a,int b){
    return a>b;
}

void dfs(int idx,int num,int add_n,int max_n,int last){
    if(add_n>2*max_n&&num>=3&&last==idx-1){
        answer=(answer+1)%MOD;
    }
    if(idx>n){
        return;
    }
    if(num+n-idx+1<3){
        return;
    }
    if(add_n+d[n]-d[idx-1]<=2*max_n){
        return;
    }
    dfs(idx+1,num+1,add_n+a[idx],max(max_n,a[idx]),idx);
    dfs(idx+1,num,add_n,max_n,last);

}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
       cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        d[i]=d[i-1]+a[i];
    }
    dfs(1,0,0,-1,0);
    cout<<answer;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
