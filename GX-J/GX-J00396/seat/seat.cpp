#include<bits/stdc++.h>

using namespace std;

long long n,m,a[110],k,f=1,c=1,p=1;

int main(){

   freopen("seat.in","r",stdin);

  freopen("seat.out","w",stdout);

    cin>>n>>m;

    for(int i=0;i<n*m;i++){

            cin>>a[i];

    }
    k=a[0];

    sort(a,a+n*m);

    for(int i=n*m-1;i>=0;i--){

        if(a[i]==k){

            cout<<c<<" "<<p;

            return 0;

        }else{

            if(f==1){

                p++;

                if(p>n){

                    p=n;

                    c++;

                    f=0;

                }

            }else{

                p--;

                if(p<1){

                    p=1;

                    c++;

                    f=1;

                }

            }

        }

    }

    return 0;

}
