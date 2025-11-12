#include<bits/stdc++.h>
using namespace std;
int T,n,a,b,c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		
		cin>>n;
		int cnt[3]={n/2},ans;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			ans+=max(a,max(b,c));
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
