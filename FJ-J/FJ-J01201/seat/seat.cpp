# include <bits/stdc++.h>
# define N 20
using namespace std;
inline int read() {
	int w=0,f=1; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-1;
	for(;isdigit(ch);ch=getchar()) w=(w<<1)+(w<<3)+(ch^48);
	return w*f;
}
struct D {
	int sum,id;
	bool operator <(const D &v) const {
		return sum>v.sum;
	}
}a[N*N];
int n,m,fx;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++)
	  a[i].sum=read(),a[i].id=i;
	sort(a+1,a+1+n*m); int pd=1;
	for(int j=1;j<=m;j++) {
	  if(!fx) {
	    for(int i=1;i<=n;i++) {
	      if(a[pd].id==1) {
	        printf("%d %d",j,i);
	        return 0;
		  }
		  pd++;
		}
	  }
	  else {
	    for(int i=n;i;i--) {
	      if(a[pd].id==1) {
	        printf("%d %d",j,i); 
			return 0;
		  }
		  pd++;
		}
	  }
	  fx^=1;
	}
	return 0;
}
//2 2
//99 100 97 98

//2 2
//98 99 100 97

//3 3
//94 95 96 97 98 99 100 93 92
