#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353; 
int a[555];
long long ans[505];
int cnt=0,cnt2=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	//int nn=n;
	cin>>n>>m;
	string s;
	cin>>s;
	int id=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0')id=1;
		if(s[i]=='1')cnt++;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0)cnt2++;
	}	
	if(id==0){
		ans[1]=1,ans[2]=2;
		for(int i=3;i<=n;i++){
			ans[i]=i*ans[i-1]%mod;
			cout<<ans[i]<<endl; 
		}
		cout<<ans[n]%mod;
	}
	
}
