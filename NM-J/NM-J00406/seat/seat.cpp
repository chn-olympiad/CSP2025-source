#include<bits/stdc++.h>
using namespace std;
long long q[100][100],x[100000];
int n,m,nown=1,nowm=1,a;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>x[1];
    a=x[1];
    for (int i=2;i<=n*m;i++){
        cin>>x[i];
    }
    int y=n*m;
    sort(x+1,x+1+y);
    for (int i=n*m;i>=1;i--){
        if (nowm%2==1){
            if (nown>n){
                nown=n;
                nowm++;
            }
        }
        if (nowm%2==0){
            if (nown<=0){
                nown=1;
                nowm++;
            }
        }
        if (nowm%2==1){
            q[nown][nowm]=x[i];
            nown++;
        }
        if (nowm%2==0){
            q[nown][nowm]=x[i];
            nown--;
        }

    }

    for (int i=1;i<=n*m;i++){
        for (int j=1;j<=m*n;j++){
            if (q[i][j]==a){
                cout<<j<<" "<<i;
                return 0;
            }
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
