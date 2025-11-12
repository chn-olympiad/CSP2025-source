#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=1e6;
int a[N];
bool px(int x,int y){
    return x<y;
}
bool polygon(int x){

}
int main(){
      //freeopen("polygon.in","r",stdin);
      //freeopen("polygon.out","w",stdout);
      cin>>n;
      for(int i=1;i<=n;i++){
          cin>>a[i];
      }
      sort(a+1,a+1+n,px);
      return 0;
}

