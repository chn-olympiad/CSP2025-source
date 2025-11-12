#include <bits/stdc++.h>
using namespace std;
int m,n,num=1,x,y;
int a[1001];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1])num++;
    }
        int tap=num/n;
        int tap2=num%n;
        if(tap%2==1){
            if(tap2==0){
                x=n;
                y=tap;
            }
            else{
                x=n-tap2+1;
                y=tap+1;
            }
        }
        else if(tap%2==0){
            if(tap2==0){
                x=1;
                y=tap;
            }
            else{
                x=tap2;
                y=tap+1;
            }
        }
        cout<<y<<' '<<x;
    return 0;
}
