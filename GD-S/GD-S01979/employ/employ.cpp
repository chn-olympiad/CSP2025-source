#include<bits/stdc++.h>
#define int long long
using namespace std;
const int p=998244353;
int n,k,a[505];
string s;
void sol1(){
	int ans=0;
	int p[15]={};
	for(int i=1;i<=n;i++){
		p[i]=i;
	}
	do{
		int c[15]={},res=0;
		for(int i=1;i<=n;i++){
			c[i]=a[p[i]];
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(cnt>=c[i]){
				cnt++;
				continue;
			}
			if(s[i]=='1'){
				res++;
			}
			else{
				cnt++;
			}
		}
		if(res>=k) ans++;
	}while(next_permutation(p+1,p+n+1));
	cout<<ans<<"\n";
}
void sol2(){
	for(int i=1;i<=n;i++){
		if(s[i]=='0'){
			cout<<"0\n";
			return;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			cout<<"0\n";
			return;
		}
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i%p;
	}
	cout<<ans<<"\n";
}
void sol3(){
	sort(a+1,a+n+1);
	int ans=1,fac[505]={};
	fac[0]=fac[1]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%p;
	}
	vector<int> r,cnt;
	for(int i=1;i<=n;i++){
		if(s[i]=='0') continue;
		r.push_back(i-1);
	}
	int pos=0;
	for(int i=1;i<=n;i++){
		if(pos<(int)r.size()&&a[i]>r[pos]){
			cnt.push_back(i);
			pos++;
		}
	}
	while(pos<(int)r.size()){
		cnt.push_back(n);
		pos++;
	}
	int res=0;
	for(int i=0;i<(int)cnt.size();i++){
		res+=cnt[i]-i-1;
		ans=ans*res%p;
	}
	ans=fac[n]-ans+p;
	ans%=p;
	cout<<ans<<"\n";
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=10){
		sol1();
	}
	else if(k==n){
		sol2();
	}
	else if(k==1){
		sol3();
	}
	else{
		sol2();
	}
}
