#include<bits/stdc++.h>
using namespace std;
int n,i,t;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int a,b,c;
	cin>>t>>n>>a>>b>>c;

	int j,sum,d;
	while(n%2==0) {
		for(int j; j=3; j++) {

			if(d<=n/2) {
				cout<<a+b+c;
			} else {
				break;
			}
		}
	}
	return 0;
}
