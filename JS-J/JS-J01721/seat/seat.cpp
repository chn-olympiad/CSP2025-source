#include<bits/stdc++.h>
using namespace std;
int n,m,a[105];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int s=a[0],f;
    sort(a,a+n*m,cmp);
    for(int i=0;i<n*m;i++){
        if(a[i]==s){
            f=i;
            break;
        }
    }
    cout<<f/n+1<<' ';
    if(f/n%2){
        cout<<m-f%n<<' ';
    }
    else cout<<f%n+1<<' ';
}
