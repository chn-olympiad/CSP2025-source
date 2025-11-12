#include<bits/stdc++.h>
using namespace std;
int c1[100005];
int c2[100005];
int c3[100005];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>c1[i]>>c2[i]>>c3[i];
		}
		sort(c1+1,c1+1+n,cmp);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=c1[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}


