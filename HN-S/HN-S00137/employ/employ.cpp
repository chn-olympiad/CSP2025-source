#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m,sum=1;
string s;

int a[505]={0};



signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	
	cin>>s;
	
	for(int i=0;i<n;i++){
		if(s[i]='0'){
			a[i+1]=a[i]+1;
		}
		else a[i+1]=a[i];
	}
	
	for(int i=2;i<=n;i++){
		sum=(sum*n)%998244353;
	}
	
	cout<<sum;
	
}
