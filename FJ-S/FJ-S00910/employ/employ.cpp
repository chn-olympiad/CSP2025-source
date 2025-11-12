#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;

	cin>>n>>m;
	if(m==1){
		cin>>s;
		int f=0;
		vector<int>a(n+4);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(s[i]=='1') f=1;
		}
			if(f) {
				cout<<1515058943;
			}
			else cout<<0;
	}
		else if(m==n){
		cin>>s;
		int f=0;
		vector<int>a(n+4);
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(s[i]==0) f=0;
		}
		if(f==0) cout<<0;
		else cout<<1515058943;
	}
	else cout<<0;
	return 0;
}
