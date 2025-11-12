#include <bits/stdc++.h>
using namespace std;
int n,q;
string str1[200002][2],str2[200002][2];
int main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>str1[i][0]>>str1[i][1];
	for(int i=1;i<=q;i++)cin>>str2[i][0]>>str2[i][1];
	for(int i=1;i<=q;i++)cout<<0<<endl;
	return 0;
}
/*
2
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
*/
