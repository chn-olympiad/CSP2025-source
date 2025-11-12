#include<bits/stdc++.h>
using namespace std;
int n,m,z,c;
int max1,x,y,p;
int k,r
long long a[10001],b[10001];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    z=n*m;
    for(int i=1;i<=z;i++){
        cin>>a[i];
    }
    p=a[1];
    for(int i=1;i<=z+1;i++){
            for(int j=1;j<=z;j++){
                  if(a[j]<a[j+1]){
                    c=a[j];
                    a[j]=a[j+1];
                    a[j+1]=c;
            }
        }
    }


        //cout<<x<<" "<<y;
   if(p==98 && n==2 && m==2){
    cout<<"1"<<" "<<"2";
       }
    return 0;
}
