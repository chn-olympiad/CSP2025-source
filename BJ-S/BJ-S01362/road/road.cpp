#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e4+5,M=1e6+5,inf=0x3f3f3f3f;
int n,m,k,c1,c2,ki[N][N],f[N],wi[N][N],ci[N];
ll ans=inf;
bool cu[N];
struct R{
    int u,v,w;
}r[N*N/2];
int wj[11][N/3][N/3];
bool cmp(R x,R y){
    return x.w<y.w;
}
int find(int x){
    if(x==f[x]) return x;
    return f[x]=find(f[x]);
}

void solve(ll an){
	if(an>=ans)
		return;
    int rt=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            r[++rt].u=i;
            r[rt].v=j;
            r[rt].w=wi[i][j];
        }
    }
    sort(r+1,r+rt+1,cmp);
    for(int i=1;i<=n;i++)
        f[i]=i;
    int cp=0;
    for(int i=1;i<=rt;i++){
        //cout<<r[i].w<<" ";
        if(find(r[i].u)!=find(r[i].v)){
            an+=r[i].w;
            if(an>=ans)
                return;
            cp++;
            f[f[r[i].u]]=r[i].v;
            if(cp==n-1)
                break;
        }
    }
    ans=an;
}

void sc(int x,int y){
    if(x==k){
        solve(y);
        cout<<y<<" ";
        return;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
          wj[x][i][j]=wj[x][j][i]=wj[x-1][i][j];
    sc(x+1,y);
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
          wj[x][i][j]=wj[x][j][i]=min(wj[x][i][j],ki[x][i]+ki[x][j]);
    sc(x+1,y+ci[x]);
}

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    memset(wi,inf,sizeof(wi));
    memset(wj,inf,sizeof(wj));
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>c1>>c2;
        cin>>wi[c1][c2];
        wi[c2][c1]=wi[c1][c2];
    }

    for(int s=1;s<=k;s++){
        cin>>ci[s];
        for(int i=1;i<=n;i++){
            cin>>ki[s][i];
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            wj[0][i][j]=wj[0][j][i]=wi[i][j];
    sc(1,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
