#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);	
	cin >>n>>m;
	string s;
	cin >>s;
	for(int i=1;i<=n;i++){
		int x;
		cin >>x;
	}
	cout <<s.length()+1-m;
	return 0;
}
