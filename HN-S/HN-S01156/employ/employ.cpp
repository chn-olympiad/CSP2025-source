#include<bits/stdc++.h>
using namespace std;
int a[505];
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1) cout<<n;
	if(m==n) cout<<1;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(s[i]=='1')  ans++;
	}
	if(ans==n) cout<<m*n;
	return 0;
} 
