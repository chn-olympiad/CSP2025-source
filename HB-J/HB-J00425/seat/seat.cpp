#include<bits/stdc++.h>
using namespace std;
const int inf=15;
int n,m,num,R,a[225];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    num=n*m;
    for(int i=1;i<=num;i++){
        cin>>a[i];
    }
    R=a[1];
    sort(a+1,a+num+1,cmp);
    for(int i=1;i<=num;i++){
        if(a[i]==R){
            R=i;
            break;
        }
    }
    int row=(R-1)/n+1;
    cout<<row<<' ';
    if(row%2==1){
        cout<<R-(row-1)*n;
        return 0;
    }
    cout<<n-(R-(row-1)*n)+1;
    return 0;
}
