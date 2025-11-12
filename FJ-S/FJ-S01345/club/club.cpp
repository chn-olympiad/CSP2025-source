#include <bits/stdc++.h>
using namespace std;
int n,t,a1[100001],a2[100001],a3[100001];
int ans;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a1[i]>>a2[i]>>a3[i];
		}
		sort(a1+1,a1+1+n);
		for(int i=n;i>n/2;i--){
			ans+=a1[i];
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}