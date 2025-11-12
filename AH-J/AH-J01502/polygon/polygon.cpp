#include "iostream"
#include "cstdio"
#include "vector"
#include "algorithm"
using namespace std;
int a[1000005],n,ans=0;
void dfs (int l,int r,int s,int sum){
	for (int i=s+1;i<r;i++){
		if (sum+a[i]>2*a[r]) ans++;
		dfs (l,r,i,sum+a[i]);
	}
}
int main(){
	freopen ("polygon.in","r",stdin);
	freopen ("polygon.out","w",stdout);
	scanf ("%d",&n);
	for (int i=1;i<=n;i++){
		scanf ("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for (int i=3;i<=n;i++){
		dfs (1,i-1,0,0);
	}
	return 0;
}
