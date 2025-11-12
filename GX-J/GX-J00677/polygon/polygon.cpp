#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
bool cmp(int a,int b){
    return a<b;
}
bool judge(long long a,int b){
    return a>(b*2);
}
bool used[5000];
long long  n,sum=0,js=0,sub[10000][5000];
void dfs(int *stick,int p){
    if(p==n)return;
    for(int i=p;i<n;i++){
        if(!used[i]){
            used[i]=1;
            sum+=stick[i];
            if(judge(sum,stick[i])&&p>=2){
                    sub[sum][p]+=1;
            }
            dfs(stick,i+1);
            sum-=stick[i];
            used[i]=0;
        }
    }
    js%=998244353;
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    int stick[n];
    for(int i=0;i<n;i++)cin>>stick[i];
    sort(stick,stick+n,cmp);
    memset(sub,0,sizeof(sub));
    dfs(stick,0);
    for(int i=0;i<10000;i++){
        for(int j=0;j<5000;j++){
        if(sub[i][j]){
            cout<<i<<" "<<j<<" "<<sub[i][j]<<endl;
            ++js;
        }
        }
    }
    cout<<js<<endl;
    return 0;
}
