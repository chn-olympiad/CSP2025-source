#include<bits/stdc++.h>
using namespace std;

int a[110];

int cj;



int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;int c,r;
    for(int i=1;i<=n*m;i++){
        cin>>a[i];
    }


    int s;

    for(int i=1;i<=n*m;i++){

        int s=a[1];
        sort(a+1,a+1+n*m);

    break;

    }

        for(int i=1;i<=n*m;i++){
            if(s==a[i]){
                c=i/n;
                r=i%n;
            }
        }
    cout<<c<<" "<<r;





    return 0;
}




