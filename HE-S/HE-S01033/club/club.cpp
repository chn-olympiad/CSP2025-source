#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	const int maxn=1e5;
	int my[maxn];
	cin>>t>>n;
	int num=0,m=0,r=0;
	int cnt1=0,a=n/2;;
	int  cnt2=0;
	int cnt3=0;
	do {
		for(int x=0; x<t; x++) {
			for(int j=0; j<n; j++) {
				for(int i=1; i<=3; i++) {
					cin>>my[i];
					if(i=1) {
						cnt1++;
					}
					if(i=2) {
						cnt2++;
					}
					if(i=3) {
						cnt3++;
					}
					m=max(m,my[i]);
					num+=m;
				}
			}
			cout<<num<<endl;
		}
	} while(cnt1<=a&&cnt<=a&&cnt3<=a);

	return 0;
}
