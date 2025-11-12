#include<bits/stdc++.h>
using namespace std;
int t,n;
int a[100005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			a[i]=x;
		}int ans=0;
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++)
			ans+=a[i];
		cout<<ans<<endl;
	}
	return 0;
}
