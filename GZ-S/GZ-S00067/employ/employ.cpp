//GZ-S00067北京师范大学贵阳附属学校  刘锦宸 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,ans=1;
	cin>>n>>m;
	int a[n];
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		ans=ans*i%998;
	}
	cout<<ans;
	return 0;
} 
