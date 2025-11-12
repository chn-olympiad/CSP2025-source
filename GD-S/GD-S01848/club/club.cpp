#include<bits/stdc++.h>
using namespace std;

int t,n,a[100010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("club.in","r",stdin);	
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int x;
			cin>>a[i];
			cin>>x;
			cin>>x;
		}
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++){
			ans+=a[i];
		}
		cout<<ans<<endl;
	}
	
	
	
	return 0;
}

