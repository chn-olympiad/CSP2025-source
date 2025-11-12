#include<bits/stdc++.h>
using namespace std;
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int main()
{  int q[100001],o[100001],u[100001],y[100001];
   int t;
     1<=t<=5;
   int n,k,l,p,r;
   n==k==l==p;
   n%2==0&&2<=n<=100000;
   struct   a
   {
   	int d1;
   	int d2;
   	int d3;
   	}
     a[n+1];
	cin>>t;
	for(int j;j<=t+1;++j)
	{

	cin>>n;
	for(int i;i<=n+1;++i)
	{  cin>>a[i].d1>>a[i].d2>>a[i].d3;
	if(a[i].d1>a[i].d2&&a[i].d1>a[i].d3)
	       { k--;q[i]=a[i].d1;}
	  if(a[i].d1<a[i].d2&&a[i].d2>a[i].d3)
	       { l--; q[i]=a[i].d2;}
	  if(a[i].d3>a[i].d2&&a[i].d3>a[i].d1) { p--;q[i]=a[i].d3;}
	  }
	for(int i;i<=n+1;++i)
	{o[i]=a[i].d1;
	 u[i]=a[i].d2;
	 y[i]=a[i].d3;
	 }
	 sort(&o[1],&o[n+1]);
	 sort(&u[1],&u[n+1]);
	 sort(&y[1],&y[n+1]);
	for(int i;i<=n+1;++i)
	{r=r+q[i];}
	if(k<=n/2&&l<=n/2&&p<=n/2)
	{cout<<r;   }
	if( k>n/2 ){ for(int i;i<=n/2-k+1;++i)
	{if(u[i]>y[i]){r=r-o[i]+u[n/2-k+2-i];
	}else{r=r-o[i]+y[n/2-k+2-i];
	}
	}cout<<r;}
	if(l>n/2){for(int i;i<=n/2-l+1;++l)
	{if(o[i]>y[i]){r=r-u[i]+o[n/2-l+2-i];
	}else{r=r-u[i]+y[n/2-l+2-i];
	}
	}cout<<r;
	};
	if(p>n/2){for(int i;i<=n/2-p+1;++i){
	 if(o[i]>u[i]){r=r-y[i]+o[n/2-p+2-i];
	 }else{r=r-y[i]+u[n/2-p+2-i];
	 }   }cout<<r;
	}


	   };

	return 0;
}











