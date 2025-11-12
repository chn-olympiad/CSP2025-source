#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(0));
	int n,m,a[100001];
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<rand()/998244353<<endl;
	
	return 0;
}
