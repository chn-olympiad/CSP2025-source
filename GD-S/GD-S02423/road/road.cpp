#include<bits/stdc++.h> 
using namespace std;
int n,m,k,c[1000005],num;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		cin>>k>>k>>c[i];
	}
	sort(c+1,c+n+1);
	for(int i=m;i>1+m-n;i++){
		num+=c[i];
	}
	cout<<num;
	return 0; 
}
