#include <bits/stdc++.h>
int a[500010];
using namespace std;
int main () {
    freopen ("xor.in","r",stdin);
    freopen ("xor.out","w",stdout);
    long long n,k,sum=0;
    cin >>n >>k;
    for (int i=1;i<=n;i++) {
        cin >>a[i];
        if (a[i]==k) {
			sum++;
			a[i]=-1;
		}
    }
    for (int i=1;i<=n-1;i++) {
        for (int j=i+1;j<=n;j++) {
	        int p=a[i];
	        if (a[i]==(-1)) continue;
            for (int k=i+1;k<=j;k++) {
				if (a[k]==(-1)) {
					p=-20000;
					break;
				}
                p=p^a[k];
             }
             if (p==k) {
				 sum++;
                 for (int pp=i+1;pp<=j;pp++) a[pp]=-1;
			 }
			 
          }
      }
      cout <<sum;
      return 0;
}
