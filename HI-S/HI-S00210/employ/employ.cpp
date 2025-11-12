#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int c[600];
int ans(int n,int m){
	int sum=m+1;
	for(int i=m+1;i<n;i++){
		sum*=i;
	}
	sum=sum%998244353;
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int num;
	bool p=1;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='0'){
			p=0;
			return 0;
		}
	}
	if(p==1){
		cout<<ans(n,m);
	}
	return 0;
}

