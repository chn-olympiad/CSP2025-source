#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  int n,m,p,sum=1;
  cin>>n>>m;
  int a[n*m];
  for(int i=0;i<n*m;i++){
    cin>>a[i];
    p=a[0];
    if(a[i]>p) sum++;
  }
  sort(a,a+n*m);
  int l=1,r=1;
  for(int i=1;i<sum;i++){
        if(l%2!=0) r++;
        else r--;
        if(r>n){
            r=n;
            l++;
        }
        if(r<=0){
            r=1;
            l++;
        }
    }
    cout<<l<<" "<<r<<" ";
  return 0;
}
