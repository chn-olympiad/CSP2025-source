#include <bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int n,m;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>a[i];
    int r=a[1];
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(a[(i-1)*n+j]==r){
                int y=i,x;
                if(i%2==0)
                    x=n-j+1;
                else
                    x=j;
                cout<<y<<' '<<x;
                return 0;
            }
        }
    }
    return 0;
}
