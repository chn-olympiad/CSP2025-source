#include<bits/stdc++.h>
using namespace std;
int n,m;
int all[100005];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++){
        cin>>all[i];
    }
    int nown=all[1];
    sort(all+1,all+n*m+1,cmp);
    int nown2;
    for(int i=1;i<=n*m;i++){
        if(all[i]==nown){
            nown2=i-1;
        }
    }
    int x,y;
    x=nown2/n;
    if(x%2==1){
        y=n-(nown2%n+1)+1;
    }
    else{
        y=nown2%n+1;
    }
    cout<<x+1<<' '<<y;
    return 0;
}
