#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool flag=true;
	int a[501]={-1};
	int b[501]={-1};
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		int c=s[i-1]-'0';
		a[i]=c;
		if(a[i]==0){
			flag=false;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	if(flag){
		int ans=1;
		for(int i=1;i<n;i++){
			ans*=i;
		}
		cout<<ans;
	}
	return 0;
}
