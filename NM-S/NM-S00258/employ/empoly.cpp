#include<bits/stdc++.h>
using namespace std;
int a[100005];

int main(){
	freopen("empoly.in","r",stdin);
	freopen("empoly.out","w",stdout);
	int n,m,succ=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++) cin>>a[i];	
	sort(a+1,a+1+n);
	for(int i=0;i<n;i++){
		if(s[i]=='1') succ++;
	}
	cout<<succ;
	return 0;
}
