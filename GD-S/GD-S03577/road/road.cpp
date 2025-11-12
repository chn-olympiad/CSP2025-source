#include <bits/stdc++.h>
using namespace std;
int n,m,k,s,t,u,v,w;

int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i =1;i<=n;i++){
		cin >>u>>v>>w;s+=w;
	}
	cout << s;
	return 0;
}
