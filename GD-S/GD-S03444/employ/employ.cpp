#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,p;
long long Mod=998244353;
string s;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0){
			cnt++;
		}
	}
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			p=1;
		}
	}
	if(p==0){
		long long k=1;
		n-=cnt;
		for(int i=1;i<=n;i++){
			k*=i;
			k%=Mod;
		}
		cout<<k;
		return 0;
	}
	return 0;
}

