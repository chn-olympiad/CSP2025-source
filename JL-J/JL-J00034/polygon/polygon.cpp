#include<bits/stdc++.h>
using namespace std;
int n,a[5005];unsigned long ans;
bool used[5005];
map<string,bool>vis;
//该决定第s根木条了，所选木条长度的总和是，选了cnt个木条，
void dfs(int s,unsigned long sum,int maxn,int cnt){
    if(s>n)return;
    if(cnt>2&&sum>maxn*2){
            char x[n+1]={};
    for(int i=1;i<=n;i++)x[i-1]=used[i]+'0';

    if(!vis[x]){ans++;/*cout<<x<<"\n"*/;}
    vis[x]=1;
    return;
    }


    for(int i=s;i<=n;i++){

                int j=1;
        if(!used[i]){ used[i]=j;dfs(s+1,sum+a[i]*j,max(maxn,a[i]*j),cnt+j);used[i]=0;}

    }
}
int main(){
int ma=0;long long cnt1=0;
    freopen("polygon.in","r",stdin);
   freopen("polygon.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){scanf("%d",&a[i]);ma=max(ma,a[i]);cnt1+=a[i];}
   // printf("%lld %d\n",cnt1,ma);
    if(cnt1>ma*2)ans++;
    //sort(a,a+n);
    dfs(1,0,0,0);

    printf("%lld",ans);
    return 0;
}
