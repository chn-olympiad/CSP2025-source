#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int a[121];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int num=a[1],sum=0;
    sort(a+1,a+1+n*m,cmp);
    for(int i=1;i<=n*m;i++){
        if(num==a[i]){
            sum=i/n;
            if(i%n==0){
                sum-=1;
            }
            if(sum%2==0){
                cout<<i/n<<" "<<i;
                return 0;
            }
            else{
                cout<<i/n+1<<" "<<i%n;
                return 0;
            }
        }
    }
    return 0;
}
