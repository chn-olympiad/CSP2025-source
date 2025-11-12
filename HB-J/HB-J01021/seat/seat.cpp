#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e6;
int a[N],x=0,y=0;
int s[100][100];
int main(){
      //freeopen("seat.in","r",stdin);
      //freeopen("seat.out","w",stdout);
      cin>>n>>m;
      int r=n*m;
      int sum=0;
      for(int i=1;i<=r;i++){
           cin>>a[i];
      }
      sum=a[1];
      sort(a+1,a+1+r);
      bool flag=1;
      for(int i=r;i>=1;i--){
          if(a[i]==sum){
            int l=r-i+1;
            flag=0;
            if(l%n==0){
                x=l/n;
            }
            else x=l/n+1;
            if(l%m==0) y=m;
            else y=l%m;
            cout<<x<<" "<<y;
            return 0;
          }
      }

      return 0;
}
