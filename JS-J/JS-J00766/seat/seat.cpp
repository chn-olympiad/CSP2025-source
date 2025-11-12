#include <bits/stdc++.h>
using namespace std;
int a[150];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int s=a[1],sum;
    sort(a+1,a+n*m+1);
    for(int i=1;i<=n*m;i++){
        if(a[n*m-i+1]==s){
            sum=i;
        }
    }
    int x=sum/n;
    int y=sum%n;
    if(y==0){
        y=n;
    }
    else{
        x+=1;
    }
    if(x%2==0){
        y=n-y+1;
    }
    cout<<x<<" "<<y<<endl;
    return 0;
}
