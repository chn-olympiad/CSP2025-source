#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n=0,m=0,b;
    cin>>n>>m;
    b=n*m;
    int a[b]={0};
    for(int i=1;i<=b;i++){
        cout<<a[i];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
