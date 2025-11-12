#include<iostream>
#include<vector>
#include<ctime>
#include<queue>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
const int N = 1050;
const int M = 100050;
void solve(){
	srand(time(0));
	int n,q;
	cin>>n>>q;
	while(q--){
	cout<<rand()%10<<endl;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

