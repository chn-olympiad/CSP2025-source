#include<bits/stdc++.h>
using namespace std;
int a[10010];
int n,m,r;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(i==1) r=a[i];
    }
    sort(a+1,a+n*m+1);
    int i=1,j=1,num=n*m;
    while(num>=1){
        if(a[num]==r){
            cout<<j<<' '<<i<<endl;
            return 0;
        }
        if(i+1<=n&&j%2==1) i++;
        else if(i-1>=1&&j%2==0) i--;
        else j++;
        num--;
    }
    return 0;
}
