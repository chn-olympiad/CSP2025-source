#include <bits/stdc++.h>

using namespace std;
int a[100000];
int main()
{   freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
    int n,m,a1,x;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        a1=a[1];
    }
    for(int i=1;i<=n*m;i++){
        for(int j=1;j<=i;j++){
            if(a[j]<a[j+1])swap(a[j],a[j+1]);
            if(a[j]==a1)x=j;
        }
    }
    for(int i=1;i<=m*n;i++){
        for(int j=1;j<=i;j++){
            if(x<=n){
                cout<<x<<" "<<1<<endl;
                break;
            }
              else if(x%n==0){cout<<x/n<<" "<<n<<endl;
                              break;
        }
    }
    }
        return 0;
}
