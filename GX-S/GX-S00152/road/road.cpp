#include<bits/stdc++.h>
using namespace std;
#define LL long long
int n,m,k;
struct bian
{
    int x,y;
    LL val1;
};
bian b[1000050];
int f[10050];
bool cmp(const bian &a,const bian &b)
{
    if(a.val1<b.val1) return 1;
    return 0;
}
int find_f(int x)
{
    if(x!=f[x]) f[x]=find_f(f[x]);
    return x;
}
void unionn(int x,int y)
{
    int fx=find_f(x);
    int fy=find_f(y);
    if(fx!=fy){
        f[y]=fx;
    }
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    int u,v;
    LL val;
    int number_bian=0;
    LL ans1=0,ans2=0;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>val;
        b[i].x=u,b[i].y=v,b[i].val1=val;
    }
    sort(b+1,b+m+1,cmp);
    for(int i=1;i<m;i++){
        if(number_bian==n-1){
            break;
        }
        if(find_f(b[i].x)!=find_f(b[i].y)){
            ans1+=b[i].val1;
            unionn(b[i].x,b[i].y);
            number_bian++;
        }
    }
    LL minans=ans1;
    int change_v,a;
    //int temp=n;
    for(int i=1;i<=k;i++){
        cin>>change_v;
        for(int j=1;j<=n;j++){
            cin>>a;
            //temp++;
            //b[m+i*j].x=temp,b[m+i*j].y=j,b[];
        }
    }
    cout<<minans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
