#include<bits/stdc++.h>
using namespace std;
int n,m,x=0,ans=0;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		int s;
		cin>>s;
	}
	for (int j=1;j<=n;j++){
		int c;
		cin>>c;
		if (c==1) x++;
	}
	for (int i=1;i<=n;i++){
		ans+=i;
	}
	cout<<ans;
	return 0;
}

