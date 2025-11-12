#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m,up=0,a1=0;
    cin>>n>>m;
    int a[n*m+1];
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    a1=a[0];
    sort(a,a+n*m+1);
    for(int i=0;i<n*m;i++){
        if(a1==a[i]){
            up=n*m-i;
        }
    }
    if(up<=n){
        cout<<1<<" "<<up;
    }
    else if(up%2==1 && up>n){
        if((up/n+1)%2==0){
            cout<<up/n+1<<" "<<up%n+1;
        }else{
            cout<<up/n+1<<" "<<up%n;
        }
    }
    else{
        cout<<up/n<<" "<<up%n;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
