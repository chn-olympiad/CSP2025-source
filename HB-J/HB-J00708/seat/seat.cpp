#include<bits/stdc++.h>
using namespace std;
int a[1000];
bool cmp(int x,int y){
    return x>y;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int k;
    cin>>k;
    a[1]=k;
    for(int i=2;i<=n*m;i++){
        cin>>a[i];
    }
    sort(a+1,a+n*m+1,cmp);
    int id;
    for(int i=1;i<=n*m;i++){
        if(a[i]==k){
            id=i;
            break;
        }
    }
    cout<<(id+n-1)/n<<" ";
    if(((id+n-1)/n)%2==1)cout<<(id-1)%n+1;
    else cout<<n-(id%n)+1;
    return 0;
}