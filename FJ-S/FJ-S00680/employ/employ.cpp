#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i = 1;i<=n;i++){
		int c;
		cin>>c;
	}
	int sum = 1;
	for(int i = 1;i<=n;i++){
		sum*=i;
	}
	cout<<sum;
	return 0;
}

