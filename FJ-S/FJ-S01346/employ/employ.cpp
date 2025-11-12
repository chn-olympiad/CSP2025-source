#include<bits/stdc++.h>
using namespace std;
int n,m,sum=0;
string s;
int num[505];
long long ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]=='1') sum++;
	}
	if(sum==n){
		for(int i=2;i<=n;i++) ans*=i,ans%=998,ans%=224,ans%=353;
		cout<<ans<<endl;
	}
	return 0;
}
