#include <bits/stdc++.h>
using namespace std;
int a[1005],b[15][15];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,a1,x,y,x1,y1;
    cin >> n >> m;
    for(int i=1;i<=n*m;i++){
        cin >> a[i];
    }
    a1=a[1];
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m/2;i++){
        swap(a[i],a[n*m+1-i]);
    }
    for(int i=1;i<=n*m;i++){
        //cout << a[i];
    }
    for(int i=1;i<=n*m;i++){
        if(a[i]==a1){
            cout << i << " " << 1;
        }
    }
    //for(int i=1;i<=m*n;i++){
     //   if(y1+1>n&&x1%2==1)x1++;
     //   else if(y1-1<1&&x1%2==0)x1++;
     //   else if(x1==m&&n==y1)break;//te
    //    else{
     //       if(x1%2==0)y1--;
     //       else y1++;
     //   }
  //      b[x1][y1]=a[i];//gai
    //}
    //cout << endl << a1 << " " << n-a1%n+1 << endl;

    return 0;
}
