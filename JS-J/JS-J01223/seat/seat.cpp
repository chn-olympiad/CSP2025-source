#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[105],x=1;
int main(){
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n*m;i++){
    scanf("%d",&a[i]);
    if(a[i]>a[1])
      x++;
  }
  int X=(x-1)/n+1,Y=x%n;
  if(Y==0) Y=n;
  printf("%d %d",X,(X&1)?Y:n-Y+1);
  fclose(stdin);
  fclose(stdout);
  return 0;
}
