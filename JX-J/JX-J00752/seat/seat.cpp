#include<bits/stdc++.h>
using namespace std;
int n,m,s;
long long a[105],b[13][13],c,d,e[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];

    }
    c=a[1];
    sort(a,a+n*m+1);
    d=n*m+1;
    for(int i=1;i<=n;i++){
        s=s+1;
        if(s%2==1){
            for(int j=1;j<=m;j++){
                d--;
                b[i][j]=a[d];
                if(b[i][j]==c){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }
        if(s%2==0){
            for(int j=m;j>=1;j--){
                d--;
                b[i][j]=a[d];
                if(b[i][j]==c){
                    cout<<i<<' '<<j;
                    return 0;
                }
            }
        }

    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}


