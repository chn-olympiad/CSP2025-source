#include<bits/stdc++.h>
using namespace std;
struct node{
	int s[7];
}; 
bool cmp(node a,node b){
	return a.s[2]>b.s[2];
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		node arr[10007];
		if(n==2){
			for(int i=1;i<=n;i++){
				cin>>arr[i].s[1]>>arr[i].s[2]>>arr[i].s[3];
			}
			int ans=-1;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					if(j==i) continue;
					if(ans<arr[1].s[i]+arr[2].s[j]){
						ans=arr[1].s[i]+arr[2].s[j];
					}
				}
			}
			cout<<ans<<endl;
		}
		else if(n==4){
			for(int i=1;i<=4;i++){
				cin>>arr[i].s[1]>>arr[i].s[2]>>arr[i].s[3];
			}
			int ans=-1;
			for(int i=1;i<=3;i++){
				for(int j=1;j<=3;j++){
					for(int k=1;k<=3;k++){
						for(int l=1;l<=3;l++){
							if(i==j&&j==k||i==j&&j==l||i==k&&k==l||j==k&&k==l){
								continue;
							} 
							if(ans<arr[1].s[i]+arr[2].s[j]+arr[3].s[k]+arr[4].s[l]){
								ans=arr[1].s[i]+arr[2].s[j]+arr[3].s[k]+arr[4].s[l];
							}
						}
					}
				}
			}
			cout<<ans<<endl;
		}
		else{
			int ans=0;
			for(int i=1;i<=n;i++){
				cin>>arr[i].s[1]>>arr[i].s[2]>>arr[i].s[3];
			}
			sort(arr+1,arr+n+1,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=(arr[i].s[2]);
			}
			cout<<ans<<endl;
		}
	}
}
