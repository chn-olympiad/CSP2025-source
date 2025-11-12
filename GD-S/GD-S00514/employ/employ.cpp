#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,x;
	string s;
	cin>>n>>m>>s;
	for(int i=0;i<n;i++)cin>>x;
	n=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			n++;
		}
	}
	cout<<n*(n-1)%998244353;
	return 0;
}
