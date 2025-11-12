#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int a[N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	if(m==n){
		for(int i=0;i<n;i++){
			if(s[i]==0){
				cout<<0;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
				cout<<(n-i-1)*(n-i-2)%998244353<<'\n';
				return 0;
			}
		}
	}
	return 0;
}
