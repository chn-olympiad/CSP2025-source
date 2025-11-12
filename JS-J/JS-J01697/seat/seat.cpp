#include<bits/stdc++.h>
using namespace std;
int n,m,a[205],sy=1;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for (int i=1;i<=n*m;i++){
        cin>>a[i];
        if (i>1){
            if (a[i]>a[1]) sy++;
        }
    }
    int x=((sy-1)/n+1);
    cout<<x<<' ';
    if (x%2==1){
        cout<<sy-(x-1)*n;
    }else{
        cout<<n-(sy-(x-1)*n)+1<<endl;
    }
    return 0;
}
