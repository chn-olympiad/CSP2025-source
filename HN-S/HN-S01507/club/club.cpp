#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,sum=0,g=0,h=0,k=0;
	cin>>n;
	int c[n],s=n,l=0;
	while(n!=0) {
		sum=0
		    long long x;
		cin>>x;
		long long a[x][x],mini[n];
		for(long long  i=0; i<x; i++) {
			for(long long j=0; j<3; j++) {
				cin>>a[i][j];
			}
			for(long long  i=0; i<x; i++) {
				if(g<=n/2||h<=n/2||k<=n/2)
					mini[s]=max(a[i][0],max(a[i][1],a[i][2]));
				if(mini[i]=a[i][0]||g>=n/2) {
					g++;
					sum+=mini[i];
					continue;
				} else if(mini[i]=a[i][2]||h>=n/2) {
					h++;
					sum+=mini[i];
					continue;
				} else if(mini[i]=a[i][3]||k>=n/2) {
					k++;
					sum+=mini[i];
					continue;
				}
				sum+=mini[i];
			}
			c[s]=sum;
			s--;
		}
	}
	for(int i=n; i>=1; i--) {
		cout<<c[i]<<endl;
	}
	return 0;
}
