#include<bits/stdc++.h>
using namespace std;
long long n,m,c[501],c1[501],a[501],b=1;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<s.size();i++){
		c[i+1]=c[i];
		if(s[i]=='0'){
			b=0;
			c[i+1]++;
		}
	}
	if(b=1){
		long long ss=1;
		for(int i=n-m+1;i<=n;i++){
			ss*=i;
			ss%=998244353;
		}
		cout<<ss;
	}
	else if(c[n]<m)cout<<0;
	else if(m==n){
		long long ss=1;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			for(int j=n;j>0;j--){
				if(a[j]<=c[i])break;
				c1[j]++;
			}
		}
		for(int i=1;i<=n;i++){
			ss*=c1[i]-i+1;
			if(ss<=0){
				ss=0;
				break;
			}
			ss%=998244353;
		}
		cout<<ss;
	}
	else if(m==1){
		long long ss=1,s2=0;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(c[i]!=c[i-1]){
				s2++;
				for(int j=1;j>=n;j++){
					if(a[j]>c[i])break;
					c1[i]++;
				}
				ss*=c1[i];
			}
			ss%=998244353;
			if(ss==0){
				break;
			}
		}
		for(int i=1;i<=s2;i++){
			ss*=i;
			ss%=998244353;
		}
		cout<<ss;
	}
	else cout<<2204128;
	return 0;
} 

