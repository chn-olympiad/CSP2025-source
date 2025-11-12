#include<bits/stdc++.h>
using namespace std;
int n,m,x;
struct node{
    int num,p;
}a[114];
bool cmp(node a,node b){
    return a.p>b.p;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>x;
        a[i].num=i,a[i].p=x;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].num==1){
            x=i;
            break;
        }
    }
    cout<<(x+n-1)/n<<" ";
    if(((x+n-1)/n)%2==1) {
        if(x%n==0) cout<<n;
        else cout<<x%n;
    }
    else{
        if(x%n==0) cout<<1;
        else cout<<n-(x%n)+1;
    }
    return 0;
}