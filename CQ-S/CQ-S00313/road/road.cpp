#include<bits/stdc++.h>
using namespace std;
string s;
int c[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	int r=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			r=1;
			break;
		}
	}
	if(m==n){
		int f=0;
		for(int i=0;i<s.size();i++){
			if(s[i]=='0'){
				f==1;
			}
		}
		if(f==1){
			cout<<0;
		} 
		else{
			cout<<1;
		}
	}
	else if(r==0){
		cout<<1;
	}
	else{
		int a[s.size()],p=0,q=0;
		long long ans=0;
		for(int i=0;i<s.size();i++){
			a[i]=s[i]-'0';
			if(a[i]==1){
				p++;
			}
			else{
				q++;
			}
		}
		for(int i=1;i<=n;i++){
			if(c[i]<i-1){
				ans=1;
				for(int j=c[i];j<=i-1-c[i];j++){
					ans=(ans*j)%998244353;
				}
				p--;
			}
		} 
		if(p<=0){
			cout<<0;
		}
		else if(q==0){
			cout<<ans;
		}
		else{
			for(int i=1;i<=p;i++){
				ans=(ans*i/p)%998244353;
			} 
			cout<<ans;
		} 
	}
	return 0;
} 
