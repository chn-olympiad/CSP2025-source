#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
int t,n;
int d1[N],d2[N],d3[N];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		bool f=1;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>d1[i]>>d2[i]>>d3[i];
			if(d2[i]!=0||d3[i]!=0)f=0;
		}
		if(f){
			int ans=0;
			sort(d1+1,d1+n+1);
			for(int i=n;i>=n/2+1;--i)ans+=d1[i];
			cout<<ans<<endl;
		}
		else{
			if(n==2){
				int ans=0;
				ans=max(ans,d1[1]+d2[2]);
				ans=max(ans,d1[1]+d3[2]);
				
				ans=max(ans,d2[1]+d1[2]);
				ans=max(ans,d2[1]+d3[2]);
				
				ans=max(ans,d3[1]+d1[2]);
				ans=max(ans,d3[1]+d2[2]);
				cout<<ans<<endl;
			}
			if(n==4){
				int ans=0;
				ans=max(ans,d1[1]+d1[2]+d2[3]+d3[4]);
				ans=max(ans,d1[1]+d1[2]+d2[4]+d3[3]);
				ans=max(ans,d1[1]+d1[3]+d2[4]+d3[2]);
				ans=max(ans,d1[1]+d1[3]+d2[2]+d3[4]);
				ans=max(ans,d1[1]+d1[4]+d2[2]+d3[3]);
				ans=max(ans,d1[1]+d1[4]+d2[3]+d3[2]);
				ans=max(ans,d1[2]+d1[3]+d2[1]+d3[4]);
				ans=max(ans,d1[2]+d1[3]+d2[4]+d3[1]);
				ans=max(ans,d1[2]+d1[4]+d2[1]+d3[3]);
				ans=max(ans,d1[2]+d1[4]+d2[3]+d3[1]);
				ans=max(ans,d1[3]+d1[4]+d2[1]+d3[2]);
				ans=max(ans,d1[3]+d1[4]+d2[2]+d3[1]);
				
				
				ans=max(ans,d2[1]+d2[2]+d1[3]+d3[4]);
				ans=max(ans,d2[1]+d2[2]+d1[4]+d3[3]);
				ans=max(ans,d2[1]+d2[3]+d1[2]+d3[4]);
				ans=max(ans,d2[1]+d2[3]+d1[4]+d3[2]);
				ans=max(ans,d2[1]+d2[4]+d1[3]+d3[2]);
				ans=max(ans,d2[1]+d2[4]+d1[2]+d3[3]);
				ans=max(ans,d2[2]+d2[3]+d1[1]+d3[4]);
				ans=max(ans,d2[2]+d2[3]+d1[4]+d3[1]);
				ans=max(ans,d2[2]+d2[4]+d1[3]+d3[1]);
				ans=max(ans,d2[2]+d2[4]+d1[1]+d3[3]);
				ans=max(ans,d2[3]+d2[4]+d1[1]+d3[2]);
				ans=max(ans,d2[3]+d2[4]+d1[2]+d3[1]);
				
				ans=max(ans,d3[1]+d3[2]+d1[3]+d2[4]);
				ans=max(ans,d3[1]+d3[2]+d1[4]+d2[3]);
				ans=max(ans,d3[1]+d3[3]+d1[2]+d2[4]);
				ans=max(ans,d3[1]+d3[3]+d1[4]+d2[2]);
				ans=max(ans,d3[1]+d3[4]+d1[3]+d2[2]);
				ans=max(ans,d3[1]+d3[4]+d1[2]+d2[3]);
				ans=max(ans,d3[2]+d3[3]+d1[1]+d2[4]);
				ans=max(ans,d3[2]+d3[3]+d1[4]+d2[1]);
				ans=max(ans,d3[2]+d3[4]+d1[3]+d2[2]);
				ans=max(ans,d3[2]+d3[4]+d1[2]+d2[3]);
				ans=max(ans,d3[3]+d3[4]+d1[1]+d2[2]);
				ans=max(ans,d3[3]+d3[4]+d1[2]+d2[1]);
				
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}