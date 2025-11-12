#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int sum=0;
void dfs(int in,int s,int num,int last){
    if(in==n+1){
        if(num>=3 && s>last*2){
            sum++;
        }
        return ;
    }
    dfs(in+1,s+a[in],num+1,a[in]);
    dfs(in+1,s,num,last);
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    dfs(1,0,0,INT_MAX);
    cout<<sum;
    return 0;
}
