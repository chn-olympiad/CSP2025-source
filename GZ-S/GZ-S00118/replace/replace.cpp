//GZ-S00118 安顺市第一高级中学 商裕如
#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false)

using namespace std;
const int N=2*1e5+5;

string s_1[N],s_2[N];
int main () {
	//freopen("replace.in","r",stdin);
//	freopen("replace.out","w",stdout);
	ios;	int n,q;	cin >> n>>q;
	for(int i=1;i<=n;i++)
	cin >> s_1[i] >>s_2[i];
	for(int i=1;i<=n;i++)
		cout << s_1[i]<<s_2[i];
		
	
	
	return 0;
}
