#include<bits/stdc++.h>
using namespace std;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	string s;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int t=0,cnt=0;
		for(int i=0;i<s.size();i++){
			if(s[i]==1){
				t=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i]>=t){
				cnt++;
			}
		} 
		cout<<cnt;
	}
	else if(m==n){
		for(int i=1;i<=s.size();i++){
			if(s[i]==0) {
				cout<<0;
				return 0;
			}
		}
		int cnt=1;
		for(int i=1;i<=n;i++){
			cnt=(cnt*i)%998244353;
		}
		cout<<cnt;
	}
	else {
		int cnt=1;
		for(int i=n;i>=n-m;i--){
			cnt=(cnt*i)%998244353;
		}
		cout<<cnt;
	}
	return 0;
}
