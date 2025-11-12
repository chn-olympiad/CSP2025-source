#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
struct mz{
    int a,b;
}a[21];
int n,m;
bool px(mz x,mz y){
    return x.a>y.a;
}
void sb1(){
    sort(a+1,a+n*m+1,px);
    for(int i=1;i<=n*m;i++){
        if(a[i].b==1) cout<<"1 "<<i;
    }
}void sb2(){
    sort(a+1,a+n*m+1,px);
    for(int i=1;i<=n*m;i++){
        if(a[i].b==1) cout<<i<<" 1";
    }
}void sb3(){
    sort(a+1,a+n*m+1,px);
    for(int i=1;i<=n*m;i++){
        if(a[i].b==1){
                cout<<(i+1)/2;
            if(((i+1)/2)%2==1){
                if(i%2==1) cout<<" 1";
                if(i%2==0) cout<<" 2";
            }else if(((i+1)/2)%2==0){
                if(i%2==1) cout<<" 2";
                if(i%2==0) cout<<" 1";
            }
        }
    }
}
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  cin>>n>>m;
  for(int i=1;i<=n*m;i++) cin>>a[i].a;
  a[1].b=1;
  if(n==1){
    if(m==1) cout<<"1 1";
    else if(m<=10) sb1();
  }else if(m==1) sb2();
  else if(n==2)sb3();
  return 0;
}
