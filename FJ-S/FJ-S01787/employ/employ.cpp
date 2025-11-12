#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,a[505],m=0,b,c=0;                                                                                                                                                                                                                                                                                                                                                                                                                                                                      ;
	long long x=1;
	string s;
	cin>>n>>b>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(s[i-1]=='1'){
			m++;
		}
		if(a[i]==0){
			c++;
		}
	}
	if(m==n){
		for(int i=1;i<=m-c;i++){
			x*=i;
			x%=998244353;
		}
		cout<<x;
	}
} 
