#include<bits/stdc++.h>
using namespace std;

int n,m,x=1,y=1,k=1;
struct stu
{
  int d,r;
}a[200];

int main()
{
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin>>n>>m;
  for(int i=1;i<=n*m;i++){
    cin>>a[i].d;
    a[i].r=i;
  }
  sort(&a[1],&a[n*m],[](stu &a,stu &b){return a.d>b.d;});
  for(int i=1;i<=n*m;i++){
    if(a[i].r==1)
      break;
    if(i%n==0){
      x++;
      k++;
    }else{
      if(k%2==1){
        y++;
      }else{
        y--;
      }
    }
  }
  cout<<x<<" "<<y<<endl;
  return 0;
}
