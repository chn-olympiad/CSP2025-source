#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=5001;
bool d[MAXN];int n,a[MAXN]={};
int ans=0;
int dfs(int mx,int su,int num,int beg){
    int sum=0;
    if(num>=3){
        if(su>mx*2){
          //  for(int i=1;i<=n;i++)if(d[i]==1)cout<<a[i]<<' ';
        //cout<<endl;
            sum++;
        }
    }
    sum%=998244353;
    for(int i=beg;i<=n;i++){
        if(d[i]==0){
            d[i]=1;
            sum+=dfs(max(mx,a[i]),su+a[i],num+1,i);
            sum%=998244353;
            d[i]=0;
        }
    }
    sum%=998244353;
    return sum;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.ans","w",stdout);


    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    cout<<dfs(0,0,0,1);
}
