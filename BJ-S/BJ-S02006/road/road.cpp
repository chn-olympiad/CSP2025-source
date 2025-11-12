#include <bits/stdc++.h>
using namespace std;
struct cheng{
    int a,b,c;
}num[1000005];
int xiang[11][5001];
bool cc(cheng x,cheng y){
    return x.c<y.c;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k,f[10005],ans;
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>num[i].a>>num[i].b>>num[i].c;
    }
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            cin>>xiang[i][j];
        }
    }
    sort(num+1,num+1+m,cc);
    int gai=n;
    int j=1,d=1;
    while(true){
        if(j>=n){
            break;
        }
        if(xiang[j][1]<num[d].c){
            f[j]=j+n;
        }
        else{
            f[j]=j;
            d++;
        }
        j++;
    }
    for(int i=1;i<=n;i++){
        if(f[i]<=n){
            ans+=num[f[i]].a;
        }
        else{
            for(int l=1;l<=n;l++){
                if(l==f[i]){
                    continue;
                }
                ans+=xiang[i][l];
            }
        }
    }
    cout<<ans;
    return 0;
}
