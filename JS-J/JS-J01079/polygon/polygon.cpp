#include <bits/stdc++.h>
using namespace std;
int n,ans=0;
vector<int>a,q;
vector<vector<int>> smark;
bool rc(vector<int> mp){
    for(vector<int> i:smark){
        if(mp==i)return false;
    }
    return true;
}
void dfs(vector<int> p=q,vector<int> mark=vector<int>(5005,0)){
    for(int i=2;i<n;i++){
        if(!mark[i]&&p[i]>2*a[i]){
            ans++;
            ans%=998244353;
        }
    }
    for(int i=0;i<n;i++){
        if(!mark[i]){
            mark[i]=1;
            if(rc(mark)){
                vector<int> chalk=p;
                for(int j=0;j<n;j++){
                    chalk[j]-=a[i];
                }
                smark.push_back(mark);
                dfs(chalk,mark);
                mark[i]=0;
            }
        }
    }
}
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);

    scanf("%d",&n);
    int x;
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        a.push_back(x);
    }
    sort(a.begin(),a.end());
    q.push_back(a[0]);
    for(int i=1;i<n;i++){
        q.push_back(a[i]+q[i-1]);
    }
    dfs();
    printf("%d",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

