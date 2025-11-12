#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n+5];
		for(int i=1;i<=n;i++){
			int b,bb;
			cin>>a[i]>>b>>bb;
		}
		sort(a+1,a+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}