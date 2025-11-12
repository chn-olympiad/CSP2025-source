#include<bits/stdc++.h>
using namespace std;
int const N =1e6+10;
vector<int> v[N];
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	return 0;
}

