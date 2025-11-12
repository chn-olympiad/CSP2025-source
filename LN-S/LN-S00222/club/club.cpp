#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100010][4];
int s[400010];
bool b=1;
bool cmp(int x,int y){
    return x>y;
}
int c11[10],mama;
void dfs(int x,int sum,int h){
    c11[x]++;
    if(c11[x]>n/2){
        c11[x]--;
        return ;
    }
    if(h>=n){
        mama=max(mama,sum);
        c11[x]--;
        return;
    }
    for(int i=1;i<=3;i++){
        dfs(i,sum+a[h+1][i],h+1);
    }
    c11[x]--;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
        memset(a,0,sizeof(a));
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
            if(!(a[i][2]==0&&a[i][3]==0)) b=0;
        }
        if(n==2){
            int c=0;
            int ma=0;
            for(int i=1;i<=3;i++){
                for(int j=1;j<=3;j++){
                    if(i==j) continue;
                    ma=max(ma,a[1][i]+a[2][j]);
                }
            }
            cout<<ma<<'\n';
            continue;
        }
        if(n==4){
            int ma=0;
            int c[5];
            for(int g1=1;g1<=3;g1++){
                for(int g2=1;g2<=3;g2++){
                    for(int g3=1;g3<=3;g3++){
                        for(int g4=1;g4<=3;g4++){
                            memset(c,0,sizeof(c));
                            c[g1]++,c[g2]++,c[g3]++,c[g4]++;
                            bool r=1;
                            for(int i=1;i<=4;i++){
                                if(c[i]>2) r=0;
                            }
                            if(r) ma=max(ma,a[1][g1]+a[2][g2]+a[3][g3]+a[4][g4]);
                        }
                    }
                }
            }
            cout<<ma<<'\n';
            continue;
        }
        if(b){
            for(int i=1;i<=n;i++) s[i]=a[i][1];
            sort(s+1,s+n+1,cmp);
            long long c=0;
            for(int i=1;i<=n/2;i++) c+=s[i];
            cout<<c<<'\n';
            continue;
        }
        if(n<=15){
            memset(c11,0,sizeof(c11));
            mama=0;
            dfs(0,0,0);
            cout<<mama<<'\n';
            continue;
        }
        for(int i=1;i<=3;i++){
            for(int j=1;j<=n;j++){
                s[i*n-n+j]=a[j][i];
            }
        }
        sort(s+1,s+3*n+1,cmp);
        long long c=0;
        for(int i=1;i<=n;i++) c+=s[i];
        printf("%lld\n",c);
    }

    return 0;
}
