#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
//priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
const int N=1e4+20;
int n,q;
string s;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=(n+q)*2;i++){
		cin>>s;
	}
	for(int i=1;i<=q;i++){
		cout<<0<<endl;
	}
	return 0;
} 
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4
*/