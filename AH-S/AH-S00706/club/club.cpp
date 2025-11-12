#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[100001][4];
		//int b[100001][4][4];
		int ans=0;
		//memset(a,0,sizeof(a));
		if(n<30){
			for(int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			}
			cout<<max(a[1][1],a[2][2])<<endl;
				
		}
		
		else{
			for(int i=1;i<=n;i++){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
				
				int t3=max(a[i][1],max(a[i][2],a[i][3]));
				
				/*if(t==a[i][1]){
					b[i][3][1]=t;
				}else if(t==a[i][2]){
					b[i][3][2]=t;
				}else if(t==a[i][3]){
					b[i][3][3]=t;
				}*/
				ans+=t3;
			}
		}
		
		cout<<ans;
		cout<<endl;
		
	}
	return 0;
}
