#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[150];
int num,ans2,ans1,sum;
signed main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int diyi=a[1];
    sort(a+1,a+1+n*m);
    for(int i=n*m,j=1;i>=1;i--,j++){
        if(a[i]==diyi){
            num=j;
            break;
        }
    }
    sum=num%(m*2);
    if(sum<=n){
        ans2=sum;
        ans1=num/m;
    }else{
        ans1=num/m;
        ans2=m-(sum-m)+1;
    }
    if(num%m!=0){
        ans1++;
    }
    cout<<ans1<<" "<<ans2;
    return 0;
}
