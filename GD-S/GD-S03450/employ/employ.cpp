#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	long long n,m,q=1,ans=0,sum=0,c[10010];
	string s;
	bool a[10010]={0};
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			sum++;
		}
		if(s[i]=='1'&&sum<=c[i]){
			ans++;
		}
	}
	for(int i=1;i<=ans;i++){
		q*=i;
	}
	cout<<q%998244353;
	return 0;
}
