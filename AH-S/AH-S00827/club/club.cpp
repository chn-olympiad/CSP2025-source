#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
int n;
long long ai[4][100005];
int cnt[4];
struct node{
    int ci,id;
    bool operator<(const node &b)const{
        int g=(ci)%3+1,h=((ci)%3+1)%3+1;
        int i=(b.ci)%3+1,j=(b.ci%3+1)%3+1;
        return min(ai[ci][id]-ai[g][id],ai[ci][id]-ai[h][id])>min(ai[b.ci][b.id]-ai[i][b.id],ai[b.ci][b.id]-ai[j][b.id]);
    }
}c[4][100005];
void wat(){
    for(int i=1;i<=3;i++){
        if(cnt[i]>n/2){
            sort(c[i]+1,c[i]+1+cnt[i]);
            for(int j=n/2+1;j<=cnt[i];j++){
                int t=c[i][j].id;
                int g=i%3+1,h=(i%3+1)%3+1;
                if(ai[g][t]>ai[h][t]){
                    c[g][++cnt[g]]={g,t};
                    c[i][j].ci=c[i][j].id=0;
                }else{
                    c[h][++cnt[h]]={h,t};
                    c[i][j].ci=c[i][j].id=0;
                }
            }
            cnt[i]=n/2;
        }
    }
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
            memset(ai,0,sizeof(ai));
            memset(c,0,sizeof(ai));
            memset(cnt,0,sizeof(ai));
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d%d%d",&ai[1][i],&ai[2][i],&ai[3][i]);
        }
        for(int i=1;i<=n;i++){
            if(ai[1][i]>ai[2][i]){
                if(ai[1][i]>ai[3][i])
                    c[1][++cnt[1]]={1,i};
                else
                    c[3][++cnt[3]]={3,i};
            }else{
                if(ai[2][i]>ai[3][i])
                    c[2][++cnt[2]]={2,i};
                else
                    c[3][++cnt[3]]={3,i};
            }
        }
        wat();wat();wat();
        long long sum=0;
        for(int i=1;i<=3;i++){
            for(int j=1;j<=cnt[i];j++){
                sum+=ai[i][c[i][j].id];
            }
        }
        cout<<sum<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
