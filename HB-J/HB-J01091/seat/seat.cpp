#include<bits/stdc++.h>
using namespace std;
int a[101],b[11][11];
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int p=a[1];
    sort(a+1,a+n*m+1);
    int f=1,i1=1,j1=1;
    for(int i=n*m;i>=1;i--){
        if(a[i]==p)
        {
            cout<<j1<<" "<<i1;
            break;
        }
        if(f==1){
            b[i1][j1]==a[i];
            i1++;
        }
        if(f==2){
            b[i1][j1]==a[i];
            i1--;
        }
        if(i1==n+1){
            i1=n;
            j1++;
            f=2;
        }
        if(i1==0){
            i1=1;
            j1++;
            f=1;
        }
    }
}
