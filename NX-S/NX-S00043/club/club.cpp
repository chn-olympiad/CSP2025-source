#include<bits/stdc++.h>
using namespace std;
int ans[5];
int cong[5][10005];
int xb[5][10005];
int sum[5];
int n;
int hgd[10005][1005];
int px(int c,int x,int temp){
    while(cong[c][x]>cong[c][x-1]&&temp>1){
        swap(cong[c][x],cong[c][x-1]);
        temp--;
    }
}
int cl(int y,int x){
    ans[y]+=hgd[x][y];
    cong [y][sum[y]]=hgd[x][y];
    xb[y][sum[y]]=x;
    px(y,sum[y],sum[y]);
}
int bj(int q,int c,int a,int b){
    if(hgd[q][c]>hgd[q][a]&&hgd[q][c]>hgd[q][b]){
                sum[c]++;
                if(sum[c]<=n/2){}
                    cl(c,q);
                }
                else{
                    cong[c][sum[c]]=0;
                    if(hgd[a][xb[c][sum[c]]]>hgd[a][xb[c][sum[c]]]){
                        cl(a,xb[c][sum[c]]);
                    }
                    else cl(b,xb[c][sum[c]]);

                }
            }

int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++){
        cin>>n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin>>hgd[i][j];
            }
            bj(i,1,2,3);
            bj(i,2,1,3);
            bj(i,3,1,2);
        }

        cout<<ans[1]+ans[2]+ans[3]<<endl;

    }
return 0;
}
