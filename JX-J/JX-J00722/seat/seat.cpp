#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cnt=1;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
        if(a[i]>a[1]) cnt++;
    }
    int h=(cnt%n==0?cnt/n:cnt/n+1),l=cnt%n;
    if(h%2==0) l=n-l+1;
    cout<<h<<" "<<l;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
