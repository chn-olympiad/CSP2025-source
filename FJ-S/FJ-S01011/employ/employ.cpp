#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	
	freopen("employ.in","r","std.in")
	freopen("employ.out","w","std.out")
	int n,m;
	cin>>n>>m;
	string s;
	int cnt=0,sum=0;
	for(int i=1;s[i];i++){
		cin>>s[i];
	}
	
	for(int i=1;i<=n;i++){
		int c;
		cin>>c;
	}
	for(int i=1;i<=n;i++){
		if(n<=m){
			cout<<n;
			break;
		}
		else{
			if(i==0){
				sum++;
				if(sum==n) cnt++;
			}
			if(i==1)
			break;
		}
	}
	cout<<cnt;
	
	return 0;
}
