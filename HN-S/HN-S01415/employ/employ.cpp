#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=505;
const int mod=998244353;
int n,m;
string s;
int c[maxn];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int sum=n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]<=0){
			sum--;
		}
	}
	if(sum<m){
		cout<<0;
		return 0;
	}
	long long num=1;
	for(int i=1;i<=sum;i++){
		num*=i;
		num%=mod;
	}
	cout<<num;
	return 0;
}
