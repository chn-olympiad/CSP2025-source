#include <bits/stdc++.h>
using namespace std;
int a[10];
int main () {
   freopen ("number.in","r",stdin);
   freopen ("number.out","w",stdout);
   string x;
   cin >>x;
   int b=x.size();
   for (int i=0;i<b;i++) {
	   if (x[i]>='0' && x[i]<='9') {
		   a[x[i]-'0']++;
	   }
   }
   for (int i=9;i>=0;i--) {
	   while (a[i]>0) {
		   cout <<i;
		   a[i]--;
	   }
   }
   return 0;
 } 
