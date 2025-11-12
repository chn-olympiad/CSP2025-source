#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],rr,cs,c,r;
bool bmp(int aa,int bb)
    {
		return aa>bb;
	}
int main()
 {
  freopen("seat.in","r",stdin);
  freopen("seat.out","w",stdout);
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n*m;i++)
     {
		 scanf("%d",&a[i]);
		 if(i==1) rr=a[i];
	 }
  sort(a+1,a+1+n*m,bmp);
  for(int i=1;i<=n*m;i++)
     {
	  if(a[i]==rr) {
		            rr=i;
		            break;
	               }	 
	 }
  rr--;
  c=rr/n+1;
  if(c%2==0) r=n-rr%n;
    else r=rr%n+1;
  printf("%d %d",c,r);
  fclose(stdin);
  fclose(stdout);
  return 0;
 }
