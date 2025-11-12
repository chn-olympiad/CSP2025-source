#include<bits/stdc++.h>
using namespace std;
int n=0,t=0,i=0,j=0,g=0,ai=0,c=0,l=0;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while (i=t) {
		cin>>n;
		while (j=n) {
			while (g=3) {
				cin>>ai;
				if (ai>=c) {
					c=ai;
				} else {
					g--;
				}
				g++;
			}
			l+=c;
			c=0;
			j++;
		}
		cout<<l;
		i++;
	}

	return 0;
}



