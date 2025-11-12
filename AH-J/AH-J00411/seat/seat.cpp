#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int b[105];
int n,m,a1;
int x,y;
bool cnt(int a,int b)
{
    return a>b;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>b[i];
    }
    a1=b[0];
    sort(b,b+n*m,cnt);
    //for(int i=0;i<n*m;i++) cout<<b[i]<<endl;
    for(int i=0;i<n*m;i++){
        //cout<<b[i]<<endl;
        if(b[i]==a1){
            if((i+1)%n==0){
                //cout<<i<<" "<<1<<endl;
                x=(i+1)/n;
                y=n;
            }
            else{
                //cout<<i<<" "<<2<<endl;
                x=(i+1)/n+1;
                y=(i+1)%n;
            }
            if(x%2==0){
                //cout<<y<<endl;
                y=n-y+1;
            }
            break;
        }

    }
    cout<<x<<" "<<y<<endl;
    return 0;
}
