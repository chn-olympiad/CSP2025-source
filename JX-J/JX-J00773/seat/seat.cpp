#include<bits/std++.h>
Using namespace std;
int j,n,m,a[10050],b[10050];
main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int c = n*m;
    cin>>c>>j;
    for(int i = 1;i < j;i++){
        cin>>a[1];
    }
    for(int i = 1;i < j;i++){
        cin>>b[1];
    }
    for(int i = 1;i < a;i++){
        if(i <= c) cout << i;
        else cout << "c-i+1";
    }
    return 0;
}
