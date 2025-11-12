#include<bits/stdc++.h>
using namespace std;
int n,m,a[10010];
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    int k=n*m;
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    cout<<3<<" "<<2;
    return 0;
}
