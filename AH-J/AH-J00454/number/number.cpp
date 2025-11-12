#include<bits/stdc++.h>
using namespace std;
char c;
int shu[1114514],s;
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	while(cin>>c) {
		if(c<='9'&&c>='0') s++,shu[s]=c-48;
	}
	sort(shu+1,shu+s+1);
	for(int i=s; i>=1; i--) {
		cout<<shu[i];
	}
	return 0;
}
