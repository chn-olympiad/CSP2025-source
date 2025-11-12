#include <bits/stdc++.h>
using namespace std;

int n,a ,b,c;
int ans=0;

void f(int x,int y,int z) {
	if(x+y+z > 2*max(x,max(y,z))) {
		ans++;
	}
}

int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	cin>>a>>b>>c;
	f(a,b,c);
	cout <<ans<<endl;
	return 0;
}

