#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,ind,t,b[15][15];
int a[105],q[10];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.ans","w",stdout);
    cin>>n>>m;
    for(int i=0; i<n*m; i++)
    {
        cin>>a[i];
    }
    ind=a[0];
    sort(a,a+n*m,cmp);
    for(int i=0; i<n*m; i++)
    {
        if(a[i]==ind) t=i+1;
        //cout<<a[i]<<' ';
    }
    //cout<<t<<' '<<ind<<' ';
    for(int i=0; i<n; i++)
    {
        for(int k=0; k<n; k++) q[k]=a[k+i*n];
        if(i%2==1) reverse(q,q+n);
        for(int j=0; j<m; j++)
        {
            b[i][j]=q[j];
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(b[i][j]==ind) cout<<i+1<<' '<<j+1;
        }
    }
    //cout<<x<<' '<<y;
    return 0;
}
