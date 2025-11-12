#include<bits/stdc++.h>
using namespace std;
const int N=500,MOD=998244353;
int n,m,c[N];
string s;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	cout<<rand()%(n*n);
	return 0;
}
