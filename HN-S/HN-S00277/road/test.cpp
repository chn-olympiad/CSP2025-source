#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define pb push_back
typedef pair<int,int>pii;
typedef vector<int>vint;
const ll inf=0x3f3f3f3f3f3f3f3f;

const int N=10010,M=1000010;
int n,m,k;
signed main(){
	cin>>k;
	int ans=0;
	for(int j=0;j<(1<<k);j++){
		int f=__builtin_popcount(j);
		ans+=f+1;
	}
	cout<<ans;
	return 0;
}
/*
Ren5Jie4Di4Ling5%
*/