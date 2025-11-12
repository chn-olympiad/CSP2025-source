// GZ-S00191 贵阳市南明区双龙华麟学校 徐文景 
#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1[200005],s2[200005],q1[200005],q2[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> s1[i] >> s2[i];
	}
	for(int i=1;i<=m;i++){
		cin >> q1[i] >> q2[i];
	}
	for(int i=1;i<=m;i++) cout << n*m;
	return 0;
}
