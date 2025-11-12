#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	int a[505];
	cin>>n>>m;
	cin>>s;
	int sum=0;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=0;i<s.size();i++){
		if(s[i]=='1') sum++;
	}
	cout<<sum;
	return 0;
}
