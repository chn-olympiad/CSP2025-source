#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	int res=0;
	for(int i = 0;i<n;i++){
		int a,b,c;
		cin>>a>>b>>c;
		res+=c;
	}
	cout<<res;
	return 0;
}
