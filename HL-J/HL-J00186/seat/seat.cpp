#include<bits/stdc++.h>
using namespace std;
int n,m,g[100];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++){
		cin >> g[i];
	}
	int x=g[0];
	sort(g,g+n*m);
	if(n==1  and m==1){
		cout << 1 << " " << 1;
	}
	if(n==1){
		for(int i=0;i<m;i++){
			if(g[i]==x);
			cout << 1 << " " << m-i+1;
			break;
		}
	}
	return 0;
}
