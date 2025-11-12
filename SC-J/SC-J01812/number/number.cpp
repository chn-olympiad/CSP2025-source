#include <iostream>
#include <algorithm>
using namespace std;
const int N=1e6+3;
int num[N];
int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int cnt=0;
	for(char c:s) {
		if(c>='0' && c<='9')
			num[++cnt]=(c&15);
	}
	sort(num+1,num+cnt+1);
	for(int i=cnt;i>=1;i--) cout<<num[i];
	return 0;
}