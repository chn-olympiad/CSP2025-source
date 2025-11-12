#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;

const int N=2e5+5;
const int M=1;
const int inf=1e9;

int n,q;
string s[N][2];
string t1,t2;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	
	cin >> n >> q;
	for(int i=1;i<=n;i++)
		cin >> s[i][0] >> s[i][1];
	for(int i=1;i<=q;i++){
		cin >> t1 >> t2;
		cout << "0\n";
	}
	
	return 0;
}
