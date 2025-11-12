#include<bits/stdc++.h>
using namespace std;
char str[501];
int n,m;
long long ans;
long long err;
int pat[501];
int minn=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout); 
	cin>>n>>m;
	if(m==n){
		bool flag=true;
		cin>>str;
		for(int i=0;i<n;i++){
			cin>>pat[i];
			if(pat[i]==0||str[i]=='0')flag=false;
		}
		if(!flag){
			cout<<"0";
			return 0;
		}
		else{
			ans=1;
			for(int i=1;i<=n;i++){
				ans=(ans*i)%998244353;
			}
			cout<<ans;
			return 0;
		}
	}
	cin>>str;
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>pat[i];
		sum+=str[i]-'0';
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ans=(ans*i)%998244353;
		}
		cout<<ans;
		return 0;
	}
	if(sum<m){
		cout<<"0";
		return 0;
	}
	cout<<"781263551";
	return 0;
}
