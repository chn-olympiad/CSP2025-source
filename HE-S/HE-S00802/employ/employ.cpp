#include<bits/stdc++.h>
using namespace std;
int n,m,t;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		if(x==0){
			t++;
		}
	}
	if(n-t<m){
		cout<<0;
		return 0;
	}
	int t=1;
	for(int i=1;i<=n;i++){
		t=(i*t)%998244353;
	}
	cout<<t;
 return 0;
}
