#include<bits/stdc++.h>
using namespace std;
int t,n,a[5][100005],b[5],d[5][100005],e[100005];
bool cmp1(int u,int v){
    return a[1][u]>a[1][v];
}
bool cmp2(int u,int v){
    return a[2][u]>a[2][v];
}
bool cmp3(int u,int v){
    return a[3][u]>a[3][v];
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
             for(int j=1;j<=3;j++){
                cin>>a[j][i];
                d[j][i]=i;
             }
        }
        sort(d[1]+1,d[1]+1+n,cmp1);
        sort(d[2]+1,d[2]+1+n,cmp2);
        sort(d[3]+1,d[3]+1+n,cmp3);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                if((!e[d[j][i]])&&(b[j]<(n>>1))){
                    e[d[j][i]]=j;
                    b[j]++;
                }else{
                    if((a[j][d[j][i]]>a[e[d[j][i]]][d[j][i]])&&(b[j]<(n>>1))){
                        b[e[d[j][i]]]--;
                        b[j]++;
                        e[d[j][i]]=j;
                    }
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=a[e[i]][i];
        }
        cout<<ans;
    }
    return 0;
}
