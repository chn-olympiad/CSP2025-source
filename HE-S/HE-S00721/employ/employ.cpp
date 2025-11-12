#include <bits/stdc++.h>
using namespace std;
int n,m,a[505],sum;
char s[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]){
				sum++;
			}
		}
	}
	cout<<sum%998244353;
	return 0;
}

