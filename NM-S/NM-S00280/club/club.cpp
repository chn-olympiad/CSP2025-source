#include<bits/stdc++.h>
using namespace std;
int t,n[6],a[100005][3],ans[1000000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	int b=0;
	for(int i=0;i<t;i++){
		cin>>n[i];
		for(int j=0;j<n[i];j++){
			cin>>a[j][0];
			cin>>a[j][1];
			cin>>a[j][2];
			ans[b]=a[j][0];
			b++;
		}int ans2=0;
		sort(ans,ans+b);
		for(int j=b;j>=n[i]/2+1;j--){
			ans2+=ans[j];
		}cout<<ans2;

	}
	
	
	return 0;
}
