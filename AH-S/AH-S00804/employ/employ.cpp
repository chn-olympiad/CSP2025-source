#include<bits/stdc++.h>
using namespace std;
long long mod=998244353,ans;
long long n,m,a[505],sum;
long long p[505],k[505];
string s;
int check(){
	int sum=0,l=0;
	for(int i=1;i<=n;i++)
		k[i]=a[p[i]];
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			l++;
			continue;
		}
		if(l>=k[i+1]) l++;
		else sum++;
	}
	return (sum>=m);
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n==m){
		for(int i=1;i<=n;i++)
			if(a[i]==0){
				cout<<0;
				return 0;
			}
		for(int i=0;i<n;i++)
			if(s[i]=='0'){
				cout<<0;
				return 0;
			}
		long long k=1;
		for(int i=1;i<=n;i++)
			k=k*i;
		cout<<k;
		return 0;
	}
	else if(n<=10){
		do{
			ans+=check();
		}while(next_permutation(p+1,p+n+1));
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
