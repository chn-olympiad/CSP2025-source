#include<bits/stdc++.h>
using namespace std;
int a[100010],sum;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='1')
		sum++;
	}
	cout<<sum;
	return 0;
}