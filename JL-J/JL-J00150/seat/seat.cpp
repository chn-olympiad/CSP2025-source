#include <bits/stdc++.h>

using namespace std;
long long m,n,a[100+10],t;
int main()
{
    //freopen("seat.in","r",stdin);
    //freopen("seat.out","w",stdin);
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
        t=a[1];
    }
    sort(a+1,a+m*n+1);
    for(int i=1;i<=m*n-1;i++){
        if(a[i]==t){
            t=i;
            break;
        }
    }
    t=m*n+1-t;
    cout<<(t+n-1)/n<<" ";
    if(t%n==0&&((t+n-1)/n)%2!=0){
        cout<<n;
    }else if(t%n==0&&((t+n-1)/n)%2==0){
        cout<<"1";
    }else if(t%n==1&&((t+n-1)/n)%2!=0){
        cout<<"1";
    }else if(t%n==1&&((t+n-1)/n)%2==0){
        cout<<n;
    }else if(((t+n-1)/n)%2==0){
        cout<<n-t%n;
    }else{
        cout<<t%n;
    }

    return 0;
}
