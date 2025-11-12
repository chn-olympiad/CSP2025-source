#include<bits/stdc++.h>
using namespace std;
struct node{
    int score,id;
}a[100010];
bool cmp(node x ,node y){
    return x.score > y.score;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i].score;
        a[i].id=i;
    }
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i].id==1){
            cout<<(i+n-1)/n<<" ";
            if(((i+n-1))/n%2==1){
                cout<<(i-1)%n+1;              
            }
            else {
                cout<<n-(i-1)%n;
            }
            
        }
    }
    return 0;
}