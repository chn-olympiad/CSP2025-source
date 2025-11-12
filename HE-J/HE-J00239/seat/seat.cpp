#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 15;
int n,m,scr,sxr;
int slst[N*N];
bool st_cmp(int x,int y) {
	return x>y;
}
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m); // hang lie
	for (int i=0;i<n*m;i++)
		scanf("%d",&slst[i]);
	scr = slst[0];
	
	sort(slst,slst+n*m,st_cmp);
	for (int i=0;i<n*m;i++)
		if (scr == slst[i]) {
			sxr = i+1;
			break;
		}
		
	int c,r; // lie hang
	r = (sxr%n == 0 ? n : sxr%n);
	c = (sxr+n-1)/n;
	if (c%2==0) {
		r = n+1 - r;
	}
	printf("%d %d",c,r);
	return 0;
}

