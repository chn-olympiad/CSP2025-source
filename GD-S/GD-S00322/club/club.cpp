#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int n,b[N][4],f[N][4],g[N][4][4],vis[N],cnt[4];
struct node{int x,y,z,id;}a[N],c[N<<2];
inline bool cmp(node xx,node yy){
	return xx.id<yy.id;
}
signed main(){
    freopen("club.in","r",stdin),freopen("club.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int T;cin>>T;
    while(T--){
        cin>>n;
        memset(a,0,sizeof a);
        int suma=0,sumb=0,sumc=0;
        for(int i=1,x,y,z;i<=n;i++){
            cin>>x>>y>>z;
            b[i][1]=x,b[i][2]=y,b[i][3]=z;
            a[i]={x,y,z,i};
            suma+=x,sumb+=y,sumc+=z;
        }
        int sum=suma+sumb+sumc;
        if(n==2){
            int ans=0;
            for(int i=1;i<=3;i++){
                for(int j=1;j<=n;j++){
                    if(i==j)continue;
                    ans=max(ans,b[1][i]+b[2][j]);
                }
            }
            cout<<ans<<"\n";
            continue;
        }
        if(sum==suma||sum==sumb||sum==sumc){
            int ans=0;
            if(sum==suma){
                sort(a+1,a+n+1,[&](node xx,node yy){return xx.x>yy.x;});
                for(int i=1;i<=n/2;i++)ans+=a[i].x;
            }else if(sum==sumb){
                sort(a+1,a+n+1,[&](node xx,node yy){return xx.y>yy.y;});
                for(int i=1;i<=n/2;i++)ans+=a[i].y;
            }else if(sum==sumc){
                sort(a+1,a+n+1,[&](node xx,node yy){return xx.z>yy.z;});
                for(int i=1;i<=n/2;i++)ans+=a[i].z;
            }
            cout<<ans<<"\n";
            continue;
        }
        if(n<=10){
        	int ans=0;
        	for(int i=0;i<=n/2;i++){
        		for(int j=0;j<=n/2;j++){
        			if(i+j<n/2)continue;
        			do{
						int res=0;
        				for(int l=1;l<=n;l++){
        					if(l<=i)res+=a[i].x;
        					else if(l<=i+j)res+=a[i].y;
        					else res+=a[i].z;
						}
						ans=max(ans,res);
					}while(next_permutation(a+1,a+n+1,cmp));
				}
			}
			cout<<ans<<"\n";
			continue;
		}
        int ans=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                c[i*j].x=b[i][j];
                c[i*j].y=j;
                c[i*j].id=i;
            }
        }
        sort(c+1,c+3*n+1,[&](node xx,node yy){return xx.x>yy.y;});
        for(int i=1;i<=3*n;i++){
            if(vis[c[i].id])continue;
            if(cnt[c[i].y]<n/2){
                vis[c[i].id]=1;
                ans+=c[i].x;
                cnt[c[i].y]++;
            }
        }
        memset(vis,0,sizeof vis); 
        memset(f,0,sizeof f),memset(g,0,sizeof g);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                if(i==1){
                    f[i][j]=b[i][j],g[i][j][j]=1;
                    continue;
                }
                int x=f[i-1][1]+b[i][j],y=f[i-1][2]+b[i][j],z=f[i-1][3]+b[i][j];
                if(x>y&&x>z){
                    if(g[i-1][j][1]<n/2){
                        f[i][j]=x;
                        g[i][j][1]=g[i-1][j][1]+1;
                        g[i][j][2]=g[i-1][j][2];
                        g[i][j][3]=g[i-1][j][3];
                    }
                }
                if(y>x&&y>z){
                    if(g[i-1][j][2]<n/2){
                        f[i][j]=y;
                        g[i][j][1]=g[i-1][j][1];
                        g[i][j][2]=g[i-1][j][2]+1;
                        g[i][j][3]=g[i-1][j][3];
                    }
                }
                if(z>x&&z>y){
                    if(g[i-1][j][3]<n/2){
                        f[i][j]=z;
                        g[i][j][1]=g[i-1][j][1];
                        g[i][j][2]=g[i-1][j][2];
                        g[i][j][3]=g[i-1][j][3]+1;
                    }
                }
            }
        }
        for(int i=1;i<=3;i++)ans=max(ans,f[n][i]);
        cout<<ans<<"\n";
    }
    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
