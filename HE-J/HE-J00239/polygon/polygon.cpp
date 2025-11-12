#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 5050, MDR = 998244353;
int n,a[N],cnt;
void search(int sum,int p,int lgs) {
	if (lgs==1){
		for (int i=p+1;i<n;i++) {
			if (a[i]<sum) {cnt++; cnt%=MDR; /*printf("%d + %d \n",sum,a[i]);*/}
			else break;
		} return;
	}
	if (lgs<1 || n-p <= lgs) return;
	for (int i=p+1;i<n;i++) {
		search(sum+a[i], i, lgs-1);
	} return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	
	for (int t=0;t<n;t++) {
		for (int j=3;j<=n;j++) {
			if (n-t < j) continue;
			search(a[t],t,j-1);
		}
	}
	
	printf("%d",cnt);
	
	return 0;
}

