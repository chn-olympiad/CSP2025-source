#include<bits/stdc++.h>
using namespace std;
int s[1100],s1[1100];
int mp[100][100];
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int r;
	cin>>r;
	for(int i =1; i<=n*m-1; i++) {
		cin>>s[i];
	}
	s[n*m] = r;
	sort(s+1,s+1+n*m);
	for(int i = 1,j=n*m; i<=n*m; i++,j--) {
		s1[i]=s[j];
	}
	for(int i=1; i<=n*m; i++) {
		if(s1[i]==r) {
			int x, l = i%n;//l那列从上往下或从下往上第l个
			x=i/n;
			if(l>=1) x += 1;//第几行
			else {
				cout<<x<<" "<<n;

				return 0;
			}
			if(x%2==0) {
				cout<<x<<" "<<n-l+1;
			} else cout<<x<<" "<<l;

		}
	}
}
