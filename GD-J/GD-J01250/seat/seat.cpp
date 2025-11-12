#include <bits/stdc++.h>
using namespace std;

int n,m,nm,o,l = 1,h = 1,a[101];

int main(){
	scanf("%d%d",&n,&m);
	nm = n * m;
	for(int i = 1;i <= nm;i++) scanf("%d",&a[i]);
	o = a[1];
	sort(a + 1,a + nm + 1);
	for(int i = nm;i >= 1;i--){
		if(a[i] == o){
			printf("%d %d",l,h);
			break;
		}
		if(l % 2 == 1){
			if(h != n) ++h;
			else ++l;
		}
		else{
			if(h != 1) --h;
			else ++l;
		}
	}
}
