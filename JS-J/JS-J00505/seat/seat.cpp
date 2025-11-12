#include<bits/stdc++.h>
using namespace std;
int c[101];int y[10];int sum=0;
int main (){
    freopen("seat.in","r",stdin);
//94 95 96 97 98 99 100 93 92
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>c[i];
        sum=c[1];
    sort(c+1,c+1+m*n);
    for(int i=n*m;i>=1;i--)
    {

        if(c[i]==sum)
        {
            int y=(n*m-i)/n+1;
            cout<<(n*m-i)/n+1<<" ";
            if(y%2!=0)
                cout<<n-(n*m-i+1)%n+1;
            else cout<<(n*m-i+1)%n;
        }
    }
    return 0;
}
