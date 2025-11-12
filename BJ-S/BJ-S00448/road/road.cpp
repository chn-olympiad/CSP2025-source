#include <bits/stdc++.h>
using namespace std;
int n,m,re;
struct node{
    int v,w;
};
vector<node>ve[100000];
int du[100000];
int du2[1000000];
int ansn=1e9;
int tong[100000];
int st[1000000];
void dfs(int k,int ans){
    if(k==n+re+1){
        bool zj=0;
        for(int i=1;i<=n;i++){
            if(du[i]==0 and i>=1 and i<=n){
                zj=1;
                break;
            }
        }
        for(int i=re+1;i<=n+re;i++){
			//cout << n+1 << ' ' << k+n << 'p';
			if(du2[i]!=n){
				ans+=st[i];
			}
		}
        if(zj==0){
			
            ansn=min(ansn,ans);
        }
   
        return ;
    }
    int s=ve[k].size();
    for(int i=0;i<s;i++){
        if(du[ve[k][i].v]==0){
            du[ve[k][i].v]=1;
            du[k]=1;
            du2[k]-=1;
            du2[ve[k][i].v]-=1;
            dfs(k+1,ans-ve[k][i].w);
            du[ve[k][i].v]=0;
            du[k]=0;
            du2[k]+=1;
            du2[ve[k][i].v]+=1;
        }
    
    }
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int anso=0;
    cin >> n >> m >> re;
    for(int i=1;i<=m;i++){
        int a,b,c;
        cin >> a >> b >> c;
        ve[a].push_back({b,c});
        ve[b].push_back({a,c});
        du2[a]++;
        du2[b]++;
        anso+=c;
}
    for(int i=n+1;i<=re+n;i++){
        cin >> st[i];
        for(int j=1;j<=n;j++){
            int a;
            cin >> a;
            ve[j].push_back({i,a});
            ve[i].push_back({j,a});
            du2[i]++;
            du2[j]++;
            anso+=a;
        }
    }
   
    dfs(1,anso);
    
    fclose(stdin);
    fclose(stdout);
    return 0;
}