#include<bits/stdc++.h>
using namespace std;
int a,b,c,d[100000][3],e[10][10000],f[10000][10000]={0},num=9999999;
int g[10001][10001];
int m=0,n=1;//d city/e villige
int find (int x,int y){
    n++;
    for(int i=1;i<=a;i++){
        if(f[x][i]==y){
            m+=g[x][y];
            num=min(m,num);
            return num;
        }else if(f[x][i]==0){
            if(n==1){
                int q=9999999999;
            for(int j=1;j<=c;j++){
                q=min(q,e[j][x+1]+e[j][y+1]+e[j][1]);

            }
                m+=q;
                num=min(m,num);
                return num;
            }else{
                break;
                }

        }else{
            m+=g[x][f[x][i]];
            return find(f[x][i],y);
        }
    }
}

int main(){
                    freopen("road.in","r",stdin);
                    freopen("road.out","w",stdout);
    cin>>a>>b>>c;
    for(int i=1;i<=b;i++){
        cin>>d[i][1]>>d[i][2]>>d[i][3];
        for(int j=1;j<=a;j++){
                if(f[d[i][1]][j]==d[i][2])break;
            if(f[d[i][1]][j]==0){
                f[d[i][1]][j]=d[i][2];
            g[d[i][1]][d[i][2]]=d[i][3];
                break;
            }
        }
        for(int j=1;j<=a;j++){
            if(f[d[i][2]][j]==d[i][1])break;
            if(f[d[i][2]][j]==0){
                f[d[i][2]][j]=d[i][1];
                g[d[i][2]][d[i][1]]=d[i][3];
                break;
            }
        }
    }
    for(int i=1;i<=c;i++){
        cin>>e[i][1];
        for(int j=1;j<=a;j++){
            cin>>e[i][j];
        }
    }
    for (int i=1;i<=a;i++){
        for(int j=i;j<=a;j++){
                    num=min(num,find(i,j));
                }
        }
    cout<<num;
    }

