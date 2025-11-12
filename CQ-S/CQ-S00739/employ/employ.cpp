#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[110];
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int b=s.size(),js1=0,js2=0;
	for(int i=0;i<b;i++){
		if(s[i]==1) js1++;
	}
	a[1]=1,a[2]=2,a[3]=6;
	for(int i=4;i<=n;i++){
		a[i]=i*a[i-1];
	}
	if(m==1) cout<<a[js1];
	else if(m==n) cout<<1;
	else cout<<a[n];
	return 0;
}
