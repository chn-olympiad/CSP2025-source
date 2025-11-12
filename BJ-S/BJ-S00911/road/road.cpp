#include<bits/stdc++.h>
using namespace std;
int n,m,k,ans,ui[1000005],vi[1000005],wi[1000005],ca[15][10005],ro[15],ygct[10005];
bool fl;
bool check(){
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            if(ca[i][j]!=0 || ro[i]!=0){
                return false;
            }
        }
    }
    return true;
}
struct node{
    int city;
    int target[10005];
}from[10005],to[10005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>ui[i]>>vi[i]>>wi[i];
    }
    for(int i=1;i<=k;i++){
        cin>>ro[i];
        for(int j=1;j<=n;j++){
            cin>>ca[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        from[i].city=ui[i];
        to[i].city=vi[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            if(to[i].city==from[j].city){
                to[i].target[j]=j;
            }
            if(from[i].city==to[j].city){
                from[i].target[j]=j;
            }
        }
    }
    if(check()){
        cout<<0;
    }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(ygct[to[from[i].target[j]].city]!=1 && ygct[from[i].city]!=1){
                    ygct[to[from[i].target[j]].city]=ygct[from[i].city]=1;
                    ans+=wi[i];
                }
            }
        }
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
