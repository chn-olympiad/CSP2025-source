#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,q,a[N][3],que[N][3],ans;

void dfs(int now,int num,int x){
    if(now=n+1){
        if(num==que[x][2]){
            ans++;
        }
        return ;
    }
    if(que[x][1]+num>=a[now][1])dfs(now+1,num+a[now][2],x);
    dfs(now+1,num,x);
}
int main(){
    freopen("replace4.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        string s1,s2;
        cin>>s1>>s2;
        for(int j=0;j<s1.size();j++){
            if(s1[j]=='b')a[i][1]=j+1;
            if(s2[j]=='b')a[i][2]=j+1;
        }
        a[i][2]=a[i][2]-a[i][1];
    }

    for(int i=1;i<=q;i++){
        ans=0;
        string s1,s2;
        cin>>s1>>s2;
        for(int j=0;j<s1.size();j++){
            if(s1[j]=='b')que[i][1]=j+1;
            if(s2[j]=='b')que[i][2]=j+1;
        }
        que[i][2]=que[i][2]-que[i][1];
        dfs(1,0,i);
        cout<<ans<<'\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
