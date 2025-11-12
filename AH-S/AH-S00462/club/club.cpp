#include<bits/stdc++.h>
using namespace std;
struct club{
    int a,b,c,s;
}a[100005];
struct ob{
    int as,bs,cs,v;
}dp[100005][4];
bool cmp(club x,club y){
    return x.s>y.s;
}
int t,n;
int Msum,Mans;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            a[i].s=a[i].a+a[i].b+a[i].c;
        }
        sort(a+1,a+n+1,cmp);
        /*for(int i=1;i<=n;i++){
			cout<<a[i].a<<" "<<a[i].b<<" "<<a[i].c<<endl;
		}*/
        Msum=n/2,Mans=0;
        memset(dp,0,sizeof(dp));
        dp[1][1].v=a[1].a;
        dp[1][1].as=1;
        dp[1][2].v=a[1].b;
        dp[1][2].bs=1;
        dp[1][3].v=a[1].c;
        dp[1][3].cs=1;
        /*for(int j=1;j<=3;j++){
				cout<<dp[1][j].v<<" "<<dp[1][j].as<<" "<<dp[1][j].bs<<" "<<dp[1][j].cs<<endl;
			}
			cout<<endl;*/
        for(int i=2;i<=n;i++){
            //ob = 1
            int M=0;
            if(dp[i-1][1].as<Msum){
                if(dp[i-1][M].v<dp[i-1][1].v){
                    M=1;
                }
            }
            if(dp[i-1][2].as<Msum){
                if(dp[i-1][M].v<dp[i-1][2].v){
                    M=2;
                }
            }
            if(dp[i-1][3].as<Msum){
                if(dp[i-1][M].v<dp[i-1][3].v){
                    M=3;
                }
            }
            dp[i][1].v=dp[i-1][M].v+a[i].a;
            dp[i][1].as=dp[i-1][M].as+1;
            dp[i][1].bs=dp[i-1][M].bs;
            dp[i][1].cs=dp[i-1][M].cs;
            //ob = 2
            M=0;
            if(dp[i-1][1].bs<Msum){
                if(dp[i-1][M].v<dp[i-1][1].v){
                    M=1;
                }
            }
            if(dp[i-1][2].bs<Msum){
                if(dp[i-1][M].v<dp[i-1][2].v){
                    M=2;
                }
            }
            if(dp[i-1][3].bs<Msum){
                if(dp[i-1][M].v<dp[i-1][3].v){
                    M=3;
                }
            }
            dp[i][2].v=dp[i-1][M].v+a[i].b;
            dp[i][2].bs=dp[i-1][M].bs+1;
            dp[i][2].as=dp[i-1][M].as;
            dp[i][2].cs=dp[i-1][M].cs;
            //ob = 3
            M=0;
            if(dp[i-1][1].cs<Msum){
                if(dp[i-1][M].v<dp[i-1][1].v){
                    M=1;
                }
            }
            if(dp[i-1][2].cs<Msum){
                if(dp[i-1][M].v<dp[i-1][2].v){
                    M=2;
                }
            }
            if(dp[i-1][3].cs<Msum){
                if(dp[i-1][M].v<dp[i-1][3].v){
                    M=3;
                }
            }
            dp[i][3].v=dp[i-1][M].v+a[i].c;
            dp[i][3].as=dp[i-1][M].as;
            dp[i][3].bs=dp[i-1][M].bs;
            dp[i][3].cs=dp[i-1][M].cs+1;
            /*for(int j=1;j<=3;j++){
				cout<<dp[i][j].v<<" "<<dp[i][j].as<<" "<<dp[i][j].bs<<" "<<dp[i][j].cs<<endl;
			}
			cout<<endl;*/
        }
        for(int i=1;i<=3;i++){
            Mans=max(Mans,dp[n][i].v);
        }
        cout<<Mans<<endl;
    }
    return 0;
}
