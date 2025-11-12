#include<bits/stdc++.h>
using namespace std;
long long a[505];
int n,m;
int cnt;
int flag;
char s[505];
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cnt=0;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(s[i]=='0'){
			flag=1;
		}
		if(a[i]==0){
			cnt++;
		}
	}
	if(flag){
		cout<<0;
	}else{
		for(int i=cnt;i<=n;i++){
			ans=ans*i%998244353;
		}
	}
	cout<<ans;
	return 0;
}
