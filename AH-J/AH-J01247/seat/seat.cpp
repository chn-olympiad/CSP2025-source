#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,q=1;
    int maxn=-1;
    int c=1,y=1;
    cin >>n >>m;
    int a[105];
    int b[105];
    for(int i=1;i<=n*m;i++){
        cin >>a[i];
    }
    for(int i=1;i<=n*m;i++){
      for(int i=1;i<=n*m;i++){
            if(i!=-9){
               if(a[i]>maxn){
            maxn=a[i];
            q=i;
        }

    }
        a[q]=-9;

        b[i]=maxn;
            }

    }
    for(int i=1;i<=n*m;i++){
        cout <<b[i];
    }

    return 0;
}
