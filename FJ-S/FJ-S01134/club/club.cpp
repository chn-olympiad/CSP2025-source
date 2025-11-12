#include <bits/stdc++.h>
using namespace std;
int t;
int n;
long long a[100005][5];
long long m[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out ","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
		m[i]=a[i][1];
	}
	sort(m+1,m+n+1);
	for(int i=n;i>=n/2;i++){
		ans+=m[i];
	}
	cout<<ans<<endl;
	
}

	
	return 0;
}
