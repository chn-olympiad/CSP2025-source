#include<bits/stdc++.h>
using namespace std;
namespace leo {
  int n,k,special,ans;
  void main() {
    freopen("xor.in","r",stdin);
    freopen("xor.out","w+",stdout);
    scanf("%d %d",&n,&k);
    int * a=(int *)malloc(sizeof(int)*(n+5));
    a[0]=0;
    special=true;
	for(int i=1;i<=n;i++) {
	  scanf("%d",a+i);
	  if(a[i]>1)
	    special=0;
	}
    if(special) {
      if(k) {
        for(int i=1;i<=n;i++)
          ans+=a[i];
	  }
	  else {
	    for(int i=1;i<=n;i++)
	      if(a[i]==0)
	        ans++;
	      else
	      if(a[i-1]) {
	        ans++;
	        a[i]=0;
		  }
	  }
	}
	else {
      int last=0;
      int * pre=(int *)malloc(sizeof(int)*(n+5));
      pre[0]=0;
      for(int i=1;i<=n;i++)
        pre[i]=(pre[i-1]^a[i]);
	  for(int i=1;i<=n;i++)
	    for(int j=last+1;j<=i;j++) {
	      if((pre[i]^pre[j-1])==k) {
	        last=i;
	        ans++;
	        break;
		  }
		}
	  free(pre);
	}
	printf("%d\n",ans);
    free(a);
  }
}
int main() {
  leo::main();
}

