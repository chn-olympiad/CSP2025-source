#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
const int N=505;
string s;
int n,m,c[N];
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	sort(c+1,c+n+1);
	int ans=0;
	do {
		int now=0,cnt=0;
		for(int i=1;i<=n&&cnt<m;i++) {
			if(s[i-1]=='1'&&now<c[i]) cnt++;
			else now++;
		}
		if(cnt>=m) ans++;
	} while(next_permutation(c+1,c+n+1));
	cout<<ans;
	return 0;
}

