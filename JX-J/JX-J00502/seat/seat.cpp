#include <bits/stdc++.h>
using namespace std;
int a[110];
bool cmp(int g,int l){
    return g>l;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int x=a[1];
    int cnt=0;
    sort(a+1,a+n*m+1,cmp);
    for (int i=1;i<=n*m;i++){
        if (a[i]==x)
            cnt=i;
    }
    if (cnt%n==0)
        cout<<cnt/n<<" ";
    else{
        cout<<cnt/n+1<<" ";
    }
    if (cnt%(2*n)>n){
        cout<<2*n-cnt%(2*n)+1;
    }
    else if (cnt%(2*n)==0)
        cout<<1;
    else
        cout<<cnt%(2*n);
}
