#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[10005];
bool cmp(int a,int b){
    return a>b;
}
int score;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=m*n;i++){
        cin>>a[i];
    }
    int r = a[1];
    sort(a+1,a+n*m+1,cmp);
    for(int i = 1 ;i <= n*m ; i++)
        if(a[i] == r) score = i;
    if(score%2)
        cout<<score/n+1<<" "<<score%n;
    else
        cout<<score/n+1<<" "<<n-score%n;
    return 0;
}
