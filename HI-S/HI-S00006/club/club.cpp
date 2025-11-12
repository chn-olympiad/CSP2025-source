#include <bits/stdc++.h>
using namespace std;
int t,n,a1,b1,c1,a2,b2,c2;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t>>n;
	cin>>a1>>b1>>c1>>a2>>b2>>c2;
	int max1,max2;
	max1=max(max(a1,b1),c1);
	max2=max(max(a2,b2),c2);
	cout<<max1+max2;
	return 0;
}

