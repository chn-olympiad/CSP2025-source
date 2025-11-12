#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	int sum=1;
	cin>>s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		while(x--)sum*=x;
	}
	cout<<sum;
	return 0;
}
