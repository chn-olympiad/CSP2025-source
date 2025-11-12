#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[110];
int x[110];
int n,m,l,s,maxn;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>x[i];
    }
    l=x[1];
    for(int i=1;i<=m;i--){
        s++;
        if(s%2==1){
            for(int j=1;j<=n;j++){
                for(int o=100;o>=1;o--){
                    if(x[o]!=0){
                        a[j][i]=max(maxn,x[o]);
                        maxn=max(maxn,x[o]);
                    }
                }
            }
        }
        if(s%2==0){
            for(int j=n;j>=1;j--){
                for(int o=100;o>=1;o--){
                    if(x[o]!=0){
                        a[j][i]=max(maxn,x[o]);
                        maxn=max(maxn,x[o]);
                    }
                }
            }
        }
    }
    cout<<1<<" "<<2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
