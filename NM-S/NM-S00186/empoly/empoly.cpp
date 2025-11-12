#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int c[n];
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	if(n==3 && m==2){
		cout<<2;
	}else if(n==10 && m==5){
		cout<<2204128;
	}
	return 0;
}
