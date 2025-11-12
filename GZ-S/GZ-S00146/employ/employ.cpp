//GZ-S00146 遵义市第四初级中学 廖奕德
#include <bits/stdc++.h>
using namespace std;
int n,m,b[501],s,i;
string a;
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>a;
	for(i=1; i<=n; i++)
		cin>>b[i];
	s=1;
	for(i=1; i<=n; i++)
		s*=i;
	cout <<s;
}
