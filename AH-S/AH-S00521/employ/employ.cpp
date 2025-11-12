#include<bits/stdc++.h>
using namespace std;
int n,m,a[505],b[505],tmp;
string s;
long long ans;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=i;
		if(a[i]==0) tmp++;
	}
	bool f=1;
	for(int i=0;i<n;i++){
		if(s[i]!='1'){
			f=0;
			break;
		}
	}
	if(m==n&&!f&&tmp>0){
		cout<<0;
		return 0;
	}
	if(f){
		if(m>n-tmp){
			cout<<0;
			return 0;
		}
		ans=1;
		for(int i=1;i<=n;i++){
			ans=ans*i%998244353;
		}
		cout<<ans;
		return 0;
	}
	do{
		int res=0,cnt=0;
		for(int i=1;i<=n;i++){
			if(s[i-1]=='0'||cnt>=a[b[i]]) cnt++;
			else res++;
		}
		if(res>=m) ans=(ans+1)%998244353;
	}while(next_permutation(b+1,b+n+1));
	cout<<ans;
	return 0;
}
