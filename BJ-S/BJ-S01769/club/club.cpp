#include<bits/stdc++.h>
using namespace std;
int t,n[20005],a[5][20005][5],ans[100005],b[5][20005][5],flag=1,c[5][20005][5],e[5]={0,0,0,0,0};
struct r{
    int e,w;
};
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    r y[15][1005][3];
    cin>>t;
    for(int i=1;i<=t;i++){
        ans[i]=0;
    }
    for(int p=1;p<=t;p++){
        cin>>n[p];
        for(int i=1;i<=3;i++){
            e[i]=0;
        }
        for(int i=1;i<=n[p];i++){
            for(int j=1;j<=3;j++){
                cin>>a[p][i][j];
            }
        }
        for(int i=1;i<=n[p];i++){
            y[p][i][1].e=a[p][i][1];
            y[p][i][1].w=1;
            y[p][i][3].e=a[p][i][1];
            y[p][i][3].w=1;
            for(int j=1;j<=2;j++){
                if(y[p][i][1].e<a[p][i][j+1]){
                    y[p][i][1].e=a[p][i][j+1];
                    y[p][i][1].w=j+1;
                }
                if(y[p][i][3].e>a[p][i][j+1]){
                    y[p][i][3].e=a[p][i][j+1];
                    y[p][i][3].w=j+1;
                }
            }
        }
        for(int i=1;i<=n[p];i++){
            for(int j=1;j<=3;j++){
                if(a[p][i][j]!=y[p][i][1].e&&a[p][i][j]!=y[p][i][3].e){
                    y[p][i][2].e=a[p][i][j];
                    y[p][i][2].w=j;
                    break;
                }
            }
        }
        for(int x=1;x<=3;x++){
            for(int i=1;i<=n[p];i++){
                c[p][x][i]=y[p][i][x].e;

                b[p][x][i]=y[p][i][x].w;
            }
        }
        for(int i=1;i<=n[p];i++){
            for(int j=i+1;j<=n[p];j++){
                if(c[p][1][i]<c[p][1][j]){
                    swap(c[p][1][i],c[p][1][j]);
                    swap(b[p][1][i],b[p][1][j]);
                }
            }
        }
        int h=1;
        while(h<=n[p]){
            if(e[b[p][1][h]]<n[p]/2){
                ans[p]+=c[p][1][h];
                h+=1;
                e[b[p][1][h]]++;
            }
            else{
                break;
            }
        }
        for(int i=1;i<=n[p];i++){
            for(int j=i+1;j<=n[p];j++){
                if(c[p][2][i]<c[p][2][j]){
                    swap(c[p][2][i],c[p][2][j]);
                    swap(b[p][2][i],b[p][2][j]);
                }
            }
        }
        while(h<=n[p]){
            if(e[b[p][2][h]]<n[p]/2){
                ans[p]+=c[p][2][h];
                h+=1;
                e[b[p][2][h]]++;
            }
            else{
                break;
            }
        }
        for(int i=1;i<=n[p];i++){
            for(int j=i+1;j<=n[p];j++){
                if(c[p][3][i]<c[p][3][j]){
                    swap(c[p][3][i],c[p][3][j]);
                    swap(b[p][3][i],b[p][3][j]);
                }
            }
        }
        while(h<=n[p]){
            if(e[b[p][3][h]]<n[p]/2){
                ans[p]+=c[p][3][h];
                h+=1;
                e[b[p][3][h]]++;
            }
            else{
                break;
            }
        }
    }
    for(int i=1;i<=t;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
