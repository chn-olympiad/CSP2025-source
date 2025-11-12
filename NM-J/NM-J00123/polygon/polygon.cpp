#include<bits/stdc++.h>
using namespace std;
int n;
bool sf=false;
long long a[5005],mmo=998244353;
bool bmp(long long aa,long long bb)
    {
		return aa>bb;
	}
long long aacc(long long ji,long long gg)
   {
	long long jii=1;
	for(int i=0;i<gg;i++)
	   {
		jii*=(ji-i);
		jii%=mmo;
		if(jii==0) break;   
	   }   
	return jii;
   }
long long jiec(int qwe)
   {
	   long long he=0;
	   for(int i=0;i<=qwe/2;i++)
	      {
		   he+=aacc(n,i)/aacc(i,i);  
		  }
	   he*=2;
	   he-=(aacc(n,1)+aacc(n,2)/2+1)%mmo;
	   if(qwe%2==0) he-=(aacc(n,n/2)/aacc(n/2,n/2))%mmo;
	   he%=mmo;
	   return he;
   }
int main()
 {
  freopen("polygon.in","r",stdin);
  freopen("polygon.out","w",stdout);
  scanf("%d",&n);
  for(int i=1;i<=n;i++)
     {
		 scanf("%lld",&a[i]);
	 }
  sort(a+1,a+1+n,bmp);
  if(n<=3) {
	  sf=true;
	        if(n<=2) printf("0");
	          else {
				    if(a[1]>=a[2]+a[3]) printf("0");
				      else printf("1");
			       }
	       } 
  if(a[n]+a[n-1]>a[1]) {
	  sf=true;
	                    long long qwe=jiec(n);
	                    printf("%lld",qwe);
                       }
  if(sf==false) cout<<n*(n-2)-a[n];
  fclose(stdin);
  fclose(stdout);
  return 0;
 }
