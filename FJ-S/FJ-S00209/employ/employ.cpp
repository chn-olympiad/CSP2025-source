#include<bits/stdc++.h>

using namespace std;

const int mod=998244353;

int n,m,flag=0;
string s;
int c[10000];
int ans=0;
int aa=0,bb=0;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int len=s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='0') bb++;
		else aa++;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	if(n==bb){
		cout<<0;
		return 0;
	}
	else if(m==1){
		cout<<aa;
		return 0;
	}else if(m==n){
		if(n!=aa){
			cout<<0;
			return 0;
		}else{
			cout<<m;
			return 0;
		}
	}else if(n==aa){
		unsigned long long sum1=1,sum2=1;
		for(int i=n;i>n-m;i--)
			sum1=sum1*i%mod;
		for(int i=1;i<=m;i++)
			sum2=sum2*i%mod;
		cout<<sum1/sum2%mod;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
}
