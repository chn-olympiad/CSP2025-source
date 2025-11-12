#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[200];
    for(int i =1;i<=n*m;i++){
        cin>>a[i];
    }
    int me = a[1],mm = 1,mn =1,mme;
    sort(a+1,a+n*m);
    int b[200];
    for(int j=1;j<=n*m+1;j++){
        b[j]=a[n*m-j+1];
        if(b[j]==me){
            mme = j;
        }
    }

    int mmm = (int)ceil(mme/m);
    if(mme%(2*n)<n){
        mn = mme%(2*n);
    }
    if(mm%(2*n)==0){
        mn = 1;
    }
    if(mm%(2*n)>n){
        mn = mm%2n-n;
    }
    cout<<mmm<<" "<<mn;
    return 0;
}
