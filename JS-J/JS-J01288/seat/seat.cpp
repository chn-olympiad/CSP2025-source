#include<bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
    if(a<b)
        return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[m*n+m+n+1];
    cin>>a[0];
    a[1]=a[0];
    for(int i=2;i<=m*n;i++)
        cin>>a[i];
    sort(a+1,a+m*n+1,cmp);
    for(int i=1;i<=m*n;i++){
        if(a[0]==a[i])
        if(i%n==0){
            if((i/n)%2==0){
                cout<<i/n<<" "<<1<<endl;
            }
            else{
                cout<<i/n<<" "<<n<<endl;
            }
        }
        else{
            if((i/n+1)%2==0){
               cout<< (i/n+1) <<" "<<n+1-(i%n)<<endl;
            }
            else{
                cout<<(i/n+1)*n-i<<" "<<(i/n+1)<<endl;
            }
        }
    }
    return 0;
}
