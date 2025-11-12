#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int k;
	cin>>k;
	while(k--){
		int n,ans;
		cin>>n;
		int a[n+1][5];
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		cout<<ans;
	}
	
	fclose(stdin);
	fclose(stdout);
} 
