#include<bits/stdc++.h>
using namespace std;
const int M=998244353;
int n,m,c[5000],s;
long long ans;
char k;
bool v[5000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>k;
		if(k>'0')v[i]=1;
	}
	for(int i=1;i<=n;i++){
		cin>>c[i];
		if(c[i])s++;
	}
	if(s>=m){
		for(int i=1;i<=n;i++){
			ans=(ans*i)%M;
		}
		cout<<ans;
	}
	else cout<<0;
	return 0;
}
