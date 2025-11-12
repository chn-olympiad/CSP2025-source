#include<bits/stdc++.h>
using namespace std;
int n,m;
struct node{
    int val;
    bool flag;
}a[105];
bool cmp(node x,node y){
    return x.val>y.val;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].val;
        a[1].flag=1;
        a[i].flag=0;
    }
    sort(a+1,a+1+n*m,cmp);
    int k=0;
    for(int i=1;i<=n*m;i++){
        if(a[i].flag==1){
            k=i;
            break;
        }
    }
    int l=(k-1)/n+1;
    if(l%2==1){
        cout<<l<<' '<<(k-1)%n+1<<"\n";
    }
    else{
        cout<<l<<' '<<n-((k-1)%n+1)+1<<"\n";
    }
    return 0;
}
