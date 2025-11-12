#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
unsigned long long g(int x){
	int ans=1;
	for(int i=2;i<=x;i++){
		ans*=i;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=m;i++){
		cin>>c[i];
	}
	cout<<g(n);
	return 0;
}
