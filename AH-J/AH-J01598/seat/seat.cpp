#include <bits/stdc++.h>
using namespace std;
int a[110];
int n,m,temp;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<m*n;i++){
        cin>>a[i];
    }
    temp=a[0];
    sort(a,a+m*n,cmp);
    for(int i=0;i<m*n;i++){
        if(a[i]==temp){
            double t=i;
            int x;
            int y=ceil((t+1)/n);
            cout<<y<<" ";
            x=int(t)%n;
            if(int(y)%2==1){
                cout<<x+1;
            }else{
                cout<<n-x;
            }
        }
    }
    return 0;
}
