#include<bits/stdc++.h>
using namespace std;
int n,m,patience[505],used[505];
unsigned long ans;char ord[505];
map<string,bool >vis;
string a;
void dfs(int s){
if(s==n){int sum=0,lose=0;
    if(!vis[ord]){
        vis[ord]=1;
        for(int i=0;i<n;i++){
            if(patience[ord[i]-'0']>lose&&a[i]=='1')sum++;
            else lose++;
        }
        if(sum>=m)ans++;
    return;
    }
}
    for(int i=0;i<n;i++){

       if(!used[i]) {ord[s]=i+'0';
       used[i]=1;
        dfs(s+1/*,sum+(patience[s]>lose),lose/*+(a[s]-'0')+!(patience[s]>lose)*/);
        used[i]=0;
       }
    }
}
int main(){
freopen("employ.in","r",stdin);
freopen("employ.out","w",stdout);
scanf("%d%d",&n,&m);

cin>>a;
for(int i=0;i<n;i++)scanf("%d",&patience[i]);
//int s=unique(patience,patience+n)-patience;

dfs(0/*,0,0*/);
printf("%lld",ans);
    return 0;
}

