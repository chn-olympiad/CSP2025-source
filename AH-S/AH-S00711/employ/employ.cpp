#include<bits/stdc++.h>
using namespace std;
int c[505],a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1; i<=n; i++)
		scanf("%d",&c[i]);
	if(m==n){
		bool flag=true;
		for(int i=0; i<n; i++)
			if(s[i]=='0') flag=false;
		bool flag2=true;
		for(int i=1; i<=n; i++)
			if(c[i]==0) flag2=false;
		if(flag||flag2) puts("0");
		else{
			long long s=1;
			for(long long i=n; i>=1; i--)
				s=s*i%998244353;
			cout<<s;
		}
		return 0;
	}
	bool flag3=true;
	for(int i=0; i<n; i++)
		if(s[i]=='0') flag3=false;
	if(flag3){
		int cnt=0,k=0;
		for(int i=1; i<=n; i++)
			if(c[i]==0) cnt++;
		k=n-cnt;
		if(k<m) puts("0");
		else{
			long long s=1;
			for(long long i=n; i>=1; i--)
				s=(s*i)%998244353;
			cout<<s;
		}
	}
	return 0;
}
