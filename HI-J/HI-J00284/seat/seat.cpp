#include<bits/stdc++.h>
using namespace std;
int a[105];
bool comp(int x,int y) {
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n, m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++) 
		for(int j=1;j<=m;j++) scanf("%d",&a[i]);
	int l = a[1];
	sort(a + 1,a + 1 + n,comp);
	int c = 0,r = 0;
	for(int i=1; i<=n; i++) { 
		for(int j=1; j<=m; j++) {
			if(a[j] != a[i] && a[j - 1] == l || a[j + 1] == l)  {
				c = i;
				r = j;
			}
		}
    }
   cout << c << " " << r; 
	
	return 0;
}
