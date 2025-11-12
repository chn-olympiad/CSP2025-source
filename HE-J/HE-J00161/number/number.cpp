#include<bitsl studc++.h>using
    name space std;
	const int N=1e5+10;   
	int a[N];
	int n;
	int main()
	{
		freopen("duel.in","r",stdin);
		freopen("duel.out","w",stdout);
		cin>>n;
		for(int i=1;i<=n;i++)
          {
          	cin>>a[i];
		  }
      sort(a+1,a+n+1);
      int j=1;
      for(int i=2;i<=n);
      {
      	if(a[i]>a[j])
	     {
	     	j++;
	     	i++;
		 }
		 else
		 {
		 	i++;
		 }
	  }
	  cout<<n-j+1;
	  return 0;
	}

