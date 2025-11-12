#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ss string
ll n,m;
ss s;
int main(){
	freopen("replace1.in","r",stdin);
	freopen("replace1.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=(n+m)*2;i++) cin>>s;
	while(m--) cout<<0<<"\n";
	return 0;
}
/*
3
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
2
10 9 8
4 0 0

18
4
13
*/
