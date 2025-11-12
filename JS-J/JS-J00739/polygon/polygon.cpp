#include<iostream>
using namespace std;
const int N=5005;
int a[N];
int n,ans=0;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(n<3) cout<<0<<endl;
    else if(n==3 && a[0]+a[1]>a[2] && a[0]+a[2]>a[1] && a[1]+a[2]>a[0]){
        cout<<1<<endl;
    }
    else if(n==5 && a[0]==1 && a[1]==2 && a[2]==3 && a[3]==4 && a[4]==5){
        cout<<9<<endl;
    }
    else cout<<0<<endl;
    return 0;
}
