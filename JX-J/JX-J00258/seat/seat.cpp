#include <bits/stdc++.h>
using namespace std;
int n,m,a[105],cnt=1,x,y,z;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++)cin>>a[i];
    for(int i=0;i<n*m;i++){
        if(a[0]<a[i])cnt++;
    }
    int a=cnt/n;
    int b=cnt%n;
    if(b==0)x=a;
    else x=a+1;
    if(x%2==1&&b==0)y=m;
        else if(x%2==0&&b==0)y=1;
            else if(x%2==1)y=b;
                else y=m-b+1;
    cout<<x<<' '<<y;
    return 0;
}
