#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	for(int i =0;i>=t;i++ ){
	
	cin>>n;
	if(n=2){void rg2();}
	else{return 0;}
	return 0;
}
}
void rg2(){
	vector<int> b;
	long long a[2][3];
	cin>>a[1][1]>>a[1][2]>>a[1][3];
	cin>>a[2][1]>>a[2][2]>>a[2][3];
	for(int i=0;i>=3;i++){for(int j;j>=2;j++){
	b.push_back(a[j][i]+a[i][i]);
	}}
	int u;
	for(int j=0;j>=b.size();j++){
		b[j+1]=max(b[j],b[j+1]);
	}
	cout<<b[b.size()];
	return;
}
