#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
char s[505];
int c[505];
int add(int z){
	int sum=0;
	for(int i=1;i<=z;i++){
		sum+=i;
	} 
	return sum;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,fl=1,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]=='0')fl=0;
	}
//	int fll=1;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	sort(c+1,c+1+n);
	if(n==m){
		if(fl){
			int sum=1;
			for(int i=2;i<=n;i++){
				sum=(sum*i)%mod;
			}
			cout<<sum<<'\n';
		}else{
			cout<<0<<'\n';
		}
		exit(0);
	}
	if(m==1){
		int sum=0;
		int ct=1;
		while(s[ct]=='0')ct++;
		for(int i=1;i<=n;i++){
			int cc=c[i];
			if(cc+1>=ct)sum++;
		} 
		cout<<sum<<'\n';
		exit(0); 
	}
	if(fl){
		int sum=1;
		for(int i=2;i<=n;i++){
			sum=(sum*i)%mod;
		}
		cout<<sum<<'\n';
		exit(0);
	}
	cout<<0<<'\n';
	return 0;
}
