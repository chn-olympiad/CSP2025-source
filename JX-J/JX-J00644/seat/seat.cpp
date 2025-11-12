#include <bits/stdc++.h>

using namespace std;

int main()

{
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m=0;
    int k=0;
    cin>>n>>m;
    int a[200];
    for(int i=0;i<n*m;i++){

       cin>>a[i];

    }
    k=a[0];
    sort(a,a+n*m);

    int l,h,q=0;
    int d=-1;
    for(int i=n*m;i>=0;i--){

        if(a[i]!=0){
            if((i+1)%n==0){
                q=1;
                h=0;
                l++;
                d*=-1;

            }
            if(d==1){
                h++;
            }
            if(d==-1){
                if(q==1){
                    h=n;
                    q=0;

                }
                else{h--;}
            }
            if(a[i]==k){
                cout<<l<<" "<<h;
                break;
            }
        }
    }

}
