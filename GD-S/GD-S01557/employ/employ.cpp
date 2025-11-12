#include<bits/stdc++.h>
using namespace std;
int n,m,cnt;
string x;
int a[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>x;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		if(a[i]=='0'){
			ans=n-i;
			break;
		}
	}
	cout<<ans;
	return 0;
}

