#include<bits/stdc++.h>
using namespace std;

int n,m,c,r;
int s[100][100];

int cj[100010];
int xmcj;
int posxm;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>cj[i];
    }
    xmcj=cj[1];
    sort(cj+1,cj+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(cj[i]==xmcj){
            posxm=i;
        }
    }
    int k=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(j==1){
                s[i][j]=k;
                k++;
                continue;
            }
            if(i==1){
                if(j%2==0){ s[i][j]=s[i][j-1]+(n*2-i);}
                else s[i][j]=s[i][j-1]+1;
                continue;
            }
            if(j%2==0)s[i][j]=s[i-1][j]-1;
            else s[i][j]=s[i-1][j]+1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i][j]==posxm){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }
    return 0;
}
