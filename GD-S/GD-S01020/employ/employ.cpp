#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	char difficult[n+1]={};
	cin>>difficult;
	int hard[n+1]={};
	for(int i=1;i<=n;i++){
		cin>>hard[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		if(difficult[i]=='1'){
			ans++;
		}
	}
	cout<<ans%998%244%353<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
