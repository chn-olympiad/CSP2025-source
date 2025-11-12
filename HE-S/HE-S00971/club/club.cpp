#include<bits/stdc++.h>
using namespace std;
int n,t,ans=0;
struct f{
	int C1,C2,C3;
}a[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[j].C1>>a[j].C2>>a[j].C3;
			ans+=max(a[j].C1,max(a[j].C2,a[j].C3));
	 }
		cout<<ans; 
	} 
	return 0; 
}
