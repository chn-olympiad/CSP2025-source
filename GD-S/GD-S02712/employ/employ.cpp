#include<bits/stdc++.h>
using namespace std;
int n,m;
char c;
vector<int>a;
int s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c;
		a.push_back(int(c-'0'));
	}
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+1+n);
	long long ans=1,sum=0;
	for(int i=1;i<=n;i++){
		if(s[i]-sum>0){
			ans=ans*(s[i]-sum);
			sum++;
			ans%=998244353;
		}
	}
	cout<<ans;
	return 0;
}
