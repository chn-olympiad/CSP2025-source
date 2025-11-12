#include<bits/stdc++.h>
using namespace std;
int a[15][15],p[105],x;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>p[i];
        if(i==1) x=p[i];
    }
    sort(p+1,p+n*m+1,cmp);
    for(int i=1;i<=n;i++){
        if(i%2==1)
            for(int j=1;j<=m;j++){
                cnt++;
                if(p[cnt]==x){
                    cout<<i<<' '<<j<<endl;
                    return 0;
                }
            }

        else
            for(int j=m;j>=1;j--){
                cnt++;
                if(p[cnt]==x){
                    cout<<i<<' '<<j<<endl;
                    return 0;
                }
            }

    }
    return 0;
}
