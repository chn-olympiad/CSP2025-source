#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,cnt_;
long long sum=1;
string s;
int c[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ,out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cnt+=s[i-1]-'0';
		cin>>c[i];
	}
	cnt_=n-cnt;
	sum*=cnt;
	for(int i=n-1;i>=2;i--){
		sum*=i;
		sum%=998244353;
	}
	for(int i=1;i<=n;i++){
		if(s[i-1]-'0'==0) continue;
		long long sum_=1;
		if(c[i]<=cnt_){
			for(int j=1;j<c[i];j++){
				sum_*=j;
				sum_%=998244353;
			}
			for(int j=1;j<=n-c[i];j++){
				sum_*=j;
				sum_%=998244353;
			}
			sum=(sum+sum_)%998244353;
		}else{
			for(int j=1;j<=cnt_;j++){
				sum_*=j;
				sum_%=998244353;
			}
			for(int j=1;j<=n-cnt_-1;j++){
				sum_*=j;
				sum_%=998244353;
			}
			sum=(sum+sum_)%998244353;
		}
	}
	cout<<sum;
	return 0;
}