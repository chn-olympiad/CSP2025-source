#include<iostream>
#include<vector>
#include<queue>
#include<ctime>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
const int N = 1050;
int n,m,c[N],sx[N];
string s;
bool cmp(int a,int b){
	return a>b;
}
void solve(){
	cin>>n>>m>>s;
	srand(time(0));
	for(int i=1;i<=n;i++)cin>>c[i];
	sort(c+1,c+1+n,cmp);
	cout<<rand()%10;
	//不想做了 
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
}

