#include<bits/stdc++.h>
using namespace std;
const int N=1e5;

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==2){
			int a[4],b[4];
			for(int i=1;i<=3;i++){
				cin>>a[i];
			}
				for(int i=1;i<=3;i++){
				cin>>b[i];
			}
			sort(a+1,a+4);
			sort(b+1,b+4);
			int ans=max(a[3]+b[2],a[2]+b[3]);
			cout<<ans<<endl;
		}
		else{
			int a[N]={0},b[N]={0},c,h=0;
			for(int i=1;i<=n;i++){
				cin>>a[i]>>b[i]>>c;
				
			}	
			
			 
				int ans=0;
				int s[N]={0};
				for(int i=1;i<=n;i++){
					ans+=a[i];
					s[i]=b[i]-a[i];
				}
				sort(s+1,s+n+1);
				for(int i=n;i>n/2;i--){
					ans=ans+s[i];
				}
				cout<<ans<<endl; 
			
			
			
		
			}
		}
return 0;
	}
	

