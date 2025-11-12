#include<bits/stdc++.h>
using namespace std;
signed long g[10001][10001];
long long n,m,k;//jiedianshu bianhsu xin
signed long ans[10001][10001];

int floyd(int a,int b){
    for(int m=0;m<n;m++){
        if(g[a][m]+g[m][b]<ans[a][b])
            ans[a][b]=g[a][m]+g[m][b];
        else
            ans[a][b]=g[a][b];
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    long long a,b,c,d;
    cin>>m>>n>>k;
    for(int i=0;i<10001;i++){
            for(int j=0;j<10001;j++){
                g[i][j]=100000000;
            }
    }
    for(int i=0;i<m;i++){
       cin>>a>>b>>c;
       g[a][b]=c;
       g[b][a]=c;
    }
    for(int i=0;i<k;i++){
        cin>>d;
        cin>>a>>b>>c;
        for(int j=0;j<n;j++){
            g[m+i][j]=c+d;
        }
    }

    for(int i=0;i<10001;i++){
        for(int j=0;j<10001;j++){
            ans[i][j]=100000000;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            floyd(i,j);
        }
    }
    int tot=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tot+=ans[i][j];
        }
    }
    cout<<tot/2;
    return 0;
}
