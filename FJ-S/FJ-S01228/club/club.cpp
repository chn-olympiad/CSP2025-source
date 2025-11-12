#include <bits/stdc++.h>
using namespace std;
int t,n,ans;
struct node{
	int x,y,c; 
}a[1000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int k=n/2;
		int d=n/2;
		int z=n/2;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].c;
			if(k==0){
				a[i].x=0;
			}
			if(d==0){
				a[i].y=0;
			}
			if(z==0){
				a[i].c=0;
			}
			ans+=max(a[i].x,max(a[i].y,a[i].c));
			if(ans==a[i].x){
				k--;	
			}
			if(ans==a[i].y){
				d--;	
			}
			if(ans==a[i].y){
				z--;	
			}		
		}
		cout<<ans;
		ans-=ans;
	}
	return 0;
}
