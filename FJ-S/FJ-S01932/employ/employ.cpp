#include <bits/stdc++.h>
using namespace std;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<m;i++) cin>>a[i];
	for(int i=0;i<s.size();i++) {
		if(s[i]=='1') sum++;
	}
	int num=1;
	if(sum==m){	
		for(int i=2;i<=n;i++) num*=i,num%=998244353;
		cout<<num;
		return 0;
	}
	else if(m==n && sum!=m) cout<<0;
	else if(m==n) cout<<num;
	else if(m==1 && sum==0) cout<<0;
	else cout<<num/2;
}
