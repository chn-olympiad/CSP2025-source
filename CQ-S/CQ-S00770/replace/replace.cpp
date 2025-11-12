#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	if(n%2==0){
		cout<<m<<'\n';
		for(int i=1;i<m;i++) cout<<0<<'\n';
		return 0;
	}
	else{
		while(m--){
			cout<<0<<'\n';
		}
	}
	return 0;
}
