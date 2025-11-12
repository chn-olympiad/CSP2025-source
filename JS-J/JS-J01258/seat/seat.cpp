#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];
inline bool cmp(int& A,int& B){
    return A>B;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int R=a[1],seat=0;
    sort(a+1,a+n*m+1,cmp);
    for(int i=1;i<=n*m;i++){
        if(a[i]==R){
            seat=i;
            break;
        }
    }
    int x=ceil(seat*1.0/n),y=0;
    if(x%2==1) y=(seat-1)%n+1;
    else if(x%2==0) y=n-((seat-1)%n);
    cout<<x<<" "<<y<<"\n";
    return 0;
}