#include<bits/stdc++.h>
using namespace std;
long long a[110];
long long b[100][100];
long long h,l,xh,n,c=1;

int main(){
   freopen("seat.in","r",stdin);
freopen("seat.out","w",stdout);

    cin>>h>>l;
    n=l*h;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    xh=a[1];

    sort(a+1,a+n+1);
    for(int i=l;i>=1;i--){
        if(i%2==0){
            for(int j=1;j<=h;j++){
                b[i][j]=a[c];
                c++;

                if(b[i][j] ==xh){
                    cout<<i<<" "<<j;
                }
            }

        }else if(i%2!=0){
        for(int j=h;j>=1;j--){
            b[i][j]=a[c];
            c++;

            if(b[i][j]==xh){
                  cout<<i<<" "<<j;

            }


        }


        }
    }
    return 0;

}
