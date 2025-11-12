#include <bits/stdc++.h>
using namespace std;
const int maxn=105;

bool cmp(int a,int b){
    return a>b;
}

int n,m,a[maxn],r;

int main(){

    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);

    cin>>n>>m;
    for (int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    r=a[1];

    sort(a+1,a+n*m+1,cmp);

    for (int i=1;i<=m;i++){
        for (int j=1;j<=n;j++){
            if (a[(i-1)*n+j]==r){
                if (i%2){
                    cout<<i<<" "<<j;
                }else{
                    cout<<i<<" "<<n-j+1;
                }
            }
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
