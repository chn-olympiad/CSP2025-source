#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
typedef pair<int,int> PII;
int n,k,a[N],mp[N][N];
bool f[N];
priority_queue<PII,vector<PII>,greater<PII>> q;
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    memset(mp,-1,sizeof mp);
    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++){
            if(i==j)
                mp[i][j]=a[i];
            else
                mp[i][j]=mp[i][j-1]^a[j];

            if(mp[i][j]==k)
                q.push({j-i+1,i});
        }
    int ans=0;
    memset(f,false,sizeof f);
    while(!q.empty()){
        PII t=q.top();
        int t1,t2;
        t1=t.first,t2=t.second;
        q.pop();
        bool b=true;
        for(int i=t2;i<=t1+t2-1;i++)
            if(f[i])
                b=false;
        if(b){
            ans++;
            for(int i=t2;i<=t1+t2-1;i++)
                f[i]=true;
        }
    }
    printf("%d",ans);
    return 0;
}
