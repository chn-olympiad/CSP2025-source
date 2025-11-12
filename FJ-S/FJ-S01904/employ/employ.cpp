#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=1;
	cin>>n>>m;
	m=n;
	for(int i=0;i<n;i++){
		ans=ans*m;
		m--;
	}
	cout<<ans<<endl;
	return 0;
}
