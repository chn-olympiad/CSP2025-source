#include<bits/stdc++.h>
using namespace std;
int edge[10000][10000];
bool vi[10];
int c[10],a[10][10000];
int n,m,k;
bool book[10000];
bool ans_book[10000][10000];
bool ans_book1[10][10000];
int old_edge[10000][10000];
long long ans;
void dj(int x){
    if(book[x])return;
    for(int i=x+1;i<n;i++){
        dj(i);
        for(int j=i+1;j<n;j++){
            dj(j);
            if(edge[x][i]+edge[x][j]<edge[i][j]){
                edge[i][j]=edge[x][i]+edge[x][j];
                ans_book[i][j]=false;
                ans_book[x][i]=true;
                ans_book[x][j]=true;
            }
        }
    }
    book[x]=true;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        memset(edge+i,0x3f,sizeof(edge[0][0])*(n-i+2));
    }
    memset(a,0x3f,sizeof(a));
    int tmp1,tmp2;
    for(int i=0;i<m;i++){
        cin>>tmp1>>tmp2;
        tmp1--;tmp2--;
        if(tmp1>tmp2)swap(tmp1,tmp2);
        cin>>old_edge[tmp1][tmp2];
        edge[tmp1][tmp2]=old_edge[tmp1][tmp2];
        //ans_book[tmp1][tmp2]=true;
    }
    for(int i=0;i<k;i++){
        cin>>c[i];
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    dj(0);
    for(int i=0;i<k;i++){
        long long check=0;
        bool flag=false;
        for(int j=0;j<n;j++){
            for(int l=j+1;l<n;l++){
                int tmp3=edge[j][l]-(a[i][j]+a[i][l]);
                if(tmp3>0){
                    check+=tmp3;
                    if(check>=c[i]){
                        flag=true;
                        break;
                    }
                }
            }
            if(flag)break;
        }
        if(flag){
            ans+=c[i];
            for(int j=0;j<n;j++){
                for(int l=j+1;l<n;l++){
                    int tmp3=edge[j][l]-(a[i][j]+a[i][l]);
                    if(tmp3>0){
                        edge[j][l]=a[i][j]+a[i][l];
                        ans_book[j][l]=false;
                        ans_book1[i][j]=true;
                        ans_book1[i][l]=true;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ans_book[i][j]){
                cout<<i<<j<<endl;
                ans+=old_edge[i][j];
            }
        }
    }
    for(int i=0;i<k;i++){
        for(int j=0;j<n;j++){
            if(ans_book1[i][j]){
                cout<<i<<j<<endl;
                ans+=a[i][j];
            }
        }
    }
    cout<<ans;
}
