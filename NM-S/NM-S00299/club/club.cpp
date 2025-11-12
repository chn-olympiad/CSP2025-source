#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t,n,ans=0;
	int a[100000][5];
	cin>>t;
	while(t>0){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ans+=max(max(a[i][1],a[i][2]),a[i][3]);
		}
		cout<<ans<<endl;
		ans=0;
		t--;
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
