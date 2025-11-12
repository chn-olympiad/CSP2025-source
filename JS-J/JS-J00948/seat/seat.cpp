#include<bits/stdc++.h>
using namespace std;

int n,m,a[110],num,sum,c,r,b[20][20];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    num=n*m;
    sum=a[0];
    sort(a,a+n*m);

    for(int j=0;j<m;j++){
        for(int i=0;i<n;i++){
            b[i][j]=a[num-1];
            num--;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

            if(j%2!=0&&sum==b[n-1-i][j]){
                r=n-i;
                c=j+1;
                break;
            }else if(sum==b[i][j]){
                r=i+1;
                c=j+1;
                break;
            }
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
