#include<bits/stdc++.h>
using namespace std;
const int N=998244353;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;
	int sum=0;
	for(int i=0;i<n;i++){
		if(s[i]=='1') sum++;
	}
	if(sum<m) {
		cout<<0;
		
	}
	else if(n==m){
		int sum=1;
		for(int i=1;i<=m;i++) {
			sum*=i;
			sum%=N;
		}
		cout<<sum;
	} 
	else {
		cout<<sum;
	}
	
	return 0;
}

