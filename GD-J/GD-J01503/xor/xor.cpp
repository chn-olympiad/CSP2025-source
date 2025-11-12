#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,k,a[N],ans,sz,s[N];
vector<pair<int,int>>v;
bool flag=1;
void dfs(int id,int cnt){
    ans=max(ans,cnt);
    if(id>sz-2) return;
    for(int i=id+1;i<sz;i++)
        if(v[i].first>v[id].second)
            dfs(i,cnt+1);
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=n;i++)
        if(a[i]>1){
            flag=false;
            break;
        }
    if(!flag){
        for(int i=1;i<=n;i++){
            int sum=0;
            for(int j=i;j<=n;j++){
                sum^=a[j];
                if(sum==k) v.push_back({i,j});
            }
        }
        sz=v.size();
        for(int i=0;i<sz;i++) dfs(i,1);
        printf("%d",ans);
    }else{
        for(int i=1;i<=n;i++) s[i]=s[i-1]^a[i];
        int cnt=0;
        for(int l=1;l<=n;){
            int r=l;
            while(abs(s[r]-s[l-1])!=k) r++;
            cnt++;
            l=r+1;
        }
        printf("%d",cnt);
    }
	return 0;
}
