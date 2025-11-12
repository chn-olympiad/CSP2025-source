#include <bits/stdc++.h>
using namespace std;
int a[110];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m*n;i++){
        cin>>a[i];
    }
    int Rs=a[1],Ri;
    sort(a+1,a+m*n+1);
    for(int i=1;i<=m*n/2;i++){
        int c=a[i];
        a[i]=a[m*n-i+1];
        a[m*n+1-i]=c;
    }

    for(int i=1;i<=m*n;i++){
        if(a[i]==Rs){
            Ri=i;
        }
    }
    if(Ri%n!=0){
        cout<<Ri/n+1<<' ';
    }
    else{
        cout<<Ri/n<<' ';
    }
    if(Ri%(2*n)<=n&&Ri%(2*n)>0){
        cout<<Ri%(2*n);
    }
    else if(Ri%(2*n)==0){
        cout<<'1';
    }
    else{
        cout<<2*n-Ri%(2*n)+1;
    }
    return 0;
}
