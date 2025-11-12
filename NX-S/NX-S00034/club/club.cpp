#include <bits/stdc++.h>
using namespace std;
int n;
int a=0;
int ans1=0;
struct clud{
    int min1,w,s,c1;
}c[4];
int main(){
    freopen("clud.in","r",stdin);
    freopen("clud.out","w",stdout);
    for(int i=0;i<=4;i++){
        c[i].min1=0;
        c[i].w=0;
        c[i].s=0;
        c[i].c1=0;
    }
    cin>>n;
    int ans[n+1]={0};
    int p[n+1][10];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=3;j++){
            cin>>p[i][j];
        }
    }
    while(a<=n){
        a+=1;
        int v=max(max(p[a][1],p[a][2]),p[a][3]);
        for(int j=1;j<=3;j++){
            if(v==p[a][j]){
                if(c[j].s<=n/2){
                    ans[a]=v;
                    c[j].s+=1;
                    p[a][4]=c[j].s;
                    if(c[j].min1>v){
                        c[j].min1=v;
                        c[j].w=a;
                        c[j].c1=j;
                    }
                }
                else if(c[j].s==n/2&&v>c[j].min1){
                    a=c[j].w-1;
                    p[c[j].w][c[j].c1]=0;
                    c[j].s=p[c[j].w][4]-1;
                }
                break;
            }

        }
    }
    for(int i=1;i<=n;i++)
        ans1+=ans[i];
    cout<<ans1;
    return 0;
}
