#include <bits/stdc++.h>
using namespace std;
int a[10010][10010],ans=100000001,lina,zhuangtai[10010],lts=1;
int n,m,k;
int sousuo(int point){
    for(int i=1;i<=n;i++){
        if(a[point][i]!=0){
            if(zhuangtai[i]==0){
                lina+=a[point][i];
                zhuangtai[i]=1;
                lts++;
                if(lts==n){
                    ans=min(lina,ans);
                }else{
                    sousuo(i);
                    sousuo(point);
                }
                lts--;
                zhuangtai[i]=0;
                lina-=a[point][i];
            }
        }
    }
    return 0;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int z,b,c;
        cin>>z>>b>>c;
        a[z][b]=c;
        a[b][z]=c;
    }
    zhuangtai[1]=1;
    sousuo(1);
    cout<<ans;
	return 0;
}
