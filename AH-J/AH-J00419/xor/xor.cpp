#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#define N 1005
using namespace std;
int n,k,a[N];
int f[N][N];
struct node{
    int l,r;
};
vector<node> b;
int cnt;
bool cmp(node x,node y){
    if(x.r!=y.r) return x.r<y.r;
    return x.l<y.l;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        f[i][i]=a[i];
        if(a[i]==k){
            cnt++;
            b.push_back({i,i});
        }
    }
    //f[i][j]=f[i][j-1]^a[j]=
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            f[i][j]=f[i][j-1]^a[j];
            if(f[i][j]==k){
                cnt++;
                b.push_back({i,j});
            }
        }
    }
    sort(b.begin(),b.end(),cmp);
    int ed=b[0].r,ct=1;
    for(int i=1;i<cnt;i++){
        if(b[i].l>ed){
            ed=b[i].r;
            ct++;
        }
    }
    cout<<ct;
    /*
    cout<<endl<<endl;
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++) cout<<b[i].l<<" "<<b[i].r<<endl;
    */
    fclose(stdin);
    fclose(stdout);
    return 0;
}
