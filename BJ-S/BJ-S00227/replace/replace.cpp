#include<bits/stdc++.h>
using namespace std;
struct node{
    string a,b;
    int le1,le2;
}k[514514];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int m,n,lenth1,lenth2;
    string x,y,xp,yp;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>k[i].a>>k[i].b;
        k[i].le1=k[i].a.size();
        k[i].le2=k[i].b.size();
    }
    while(m--){
        cin>>x>>y;
        int cnt=0;
        lenth1=x.size();
        lenth2=x.size();
        for(int i=1;i<=n;i++){
            for(int j=0;j<lenth1-k[i].le1;j++){
                for(int k1=j;k1<=k[i].le1+j;k1++){
                    xp[k1]=x[k1];
                    yp[k1]=y[k1];
                    x[k1]='a';
                    y[k1]='a';
                }
                if(k[i].b==yp&&xp==k[i].a&&x==y){
                    cnt++;
                    for(int k1=j;k1<=k[i].le1+j;k1++){
                    x[k1]=xp[k1];
                    y[k1]=yp[k1];
                    break;
                }
                }
                for(int k1=j;k1<=k[i].le1+j;k1++){
                    x[k1]=xp[k1];
                    y[k1]=yp[k1];
                }
                xp=' ';
                yp=' ';
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
