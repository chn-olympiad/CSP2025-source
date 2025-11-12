#include<bits/stdc++.h>
using namespace std;
int n,m,l[110],s,ag,scp[15][15];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin >> n >> m;
    s = n*m;
    for(int i=1;i<=s;i++) cin >> l[i];
    ag = l[1];
    sort(l+1,l+s+1,cmp);
    int p;
    for(p=1;l[p]!=ag;p++);
    cout << (p-1)/n+1<< ' ' << ((((p-1)/n+1)%2==1) ? ((p-1)%n+1):(n-(p-1)%n));
    //100 97
    //99  98
    return 0;
}
