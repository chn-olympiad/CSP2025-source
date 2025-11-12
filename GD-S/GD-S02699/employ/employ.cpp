#include<bits/stdc++.h>
using namespace std;
int n,m,c[505];
string s;
const long long mod=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int bj1=0,bj2=0,js=0;
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=0;i<n;i++){
		if(s[i]=='1')	bj1=1,js++;
		if(s[i]=='0')	bj2=1;
	}		
	if(bj1==0){
		cout<<0;
		return 0;
	}
	if(m==n){
		if(bj2==1)	cout<<0;
		else	cout<<1;
		return 0;
	}
	sort(c+1,c+1+n);
	int i=1,s=0;
	while(i<=n){
		if(s==js)	break;
		if(s<=c[i])	i++,s++;
		else	i++;
	}
	if(s<m)	cout<<0;
	else{
		long long ans=1;
		for(int i=1;i<=s;i++)
			ans=(ans*i)%mod;
		for(int i=1;i<=(n-s);i++)
			ans=(ans*i)%mod;
		cout<<ans;
	}
	return 0;
}
