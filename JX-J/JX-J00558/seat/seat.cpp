#include<bits/stdc++.h>
using namespace std;
int a[105];
int r;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,k=0;
    cin>>n>>m;
    //cout<<n*m<<endl;
    for (int i=1;i<=n*m;++i){
        cin>>a[i];
    }
    r=a[1];
    //cout<<1;
    sort(a+1,a+1+n*m,cmp);

    for (int i=1;i<=n;++i){
        if (i%2){
           for (int j=1;j<=m;++j){
                k=(i-1)*n+j;
                //cout<<k<<" ";
                if (a[k]==r){
                    cout<<i<<" "<<j;
                    //return 0;
                }
            }
        }
        else {
            for (int j=m;j>=1;--j){
                k=(i-1)*n+m-j+1;
                //cout<<k<<" ";
                if (a[k]==r){
                    cout<<i<<" "<<j;
                    return 0;
                }
            }
        }
        //cout<<endl;

    }

    return 0;
}
