#include <bits/stdc++.h>
using namespace std;
int n,k,a[500001];
bool check(int x){
	int num=0;
	int c=0;
	for (int i=1;i<=n;i++){
		if(c^a[i]==k){
			num++;
			x = 0;
		}else
		    x^=a[i];
	}
	return num>=x;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf ("%d%d",&n,&k);
	for (int i=1;i<=n;i++)
	    scanf ("%d",&n);
	int l = 0,r = n+1;
	while (l+1<r){
		int m = (l+r)/2;
		if (check(m))
		    l = m;
		else
		    r = m;
	}
	printf ("%d",l);
}
