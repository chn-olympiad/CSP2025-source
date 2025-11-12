#include<bits/stdc++.h>
using namespace std;
int ds(int x){
	if(x==1) return 1;
	else return x*ds(x-1);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[n],sum=0;
	for(int i=0;i<n;i++){
		cin>>c[i];
		if(c[i]!=0) sum++;
	}
	cout<<ds(sum)%998244353;
	return 0;
}
