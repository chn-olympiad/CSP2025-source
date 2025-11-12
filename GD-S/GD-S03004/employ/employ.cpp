#include<bits/stdc++.h>
using namespace std;
int a[505];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	bool f=false;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) f=true;
	}
	if(m==n){
		if(f==true){
			cout<<0;
		}
		else{
			long long sum=1;
			for(int i=1;i<=n;i++){
				sum*=i;
			}
			cout<<sum%998244353;
		}
	}
	return 0;
}

