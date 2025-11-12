#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int a,b,c,s = 0;
	for(int i = 1;i <= n;i++){
		cin>>a>>b>>c;
		s += c;
	}
	cout<<s;
	return 0;
}
