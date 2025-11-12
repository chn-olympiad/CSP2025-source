#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long n,m,a[1000],c[1000],num,sum;
string s;
bool b[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0;i<s.size();i++){
		a[i+1]=s[i]-'0';
		if(a[i+1]==1) num++;
	}for(int i=1;i<=n;i++) cin>>c[i];
	if(num==n){
		int sum=1;
		for(int i=1;i<=n;i++){
			sum*=i;
		}cout<<sum%mod;
	}else cout<<0;
}

