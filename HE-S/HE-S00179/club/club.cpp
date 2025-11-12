#include <bits/stdc++.h>
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
		int a[n+1][4];
		long long ans=0;
		memset(a,0,sizeof(a));
		int ba[n+1];
		bool pda=true;
		bool pdB=true;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			ba[i]=a[i][1];
			if(a[i][2]==0 && a[i][3]==0){
				
			}else{
				pda=false;
			}
			if(a[i][3]!=0){
				pdB=false;
			}
		}
		if(n==2){
			int tmp1,tmp2,tmp3;
			tmp1=max(a[1][1]+a[2][2],a[1][1]+a[2][3]);
			tmp2=max(a[1][2]+a[2][1],a[1][2]+a[2][3]);
			tmp3=max(a[1][3]+a[2][1],a[1][3]+a[2][2]);
			ans=max(tmp1,max(tmp2,tmp3));
			cout<<ans<<endl;
			continue;
		}
		
		if(pda){
			
			sort(ba+1,ba+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				//cout<<"test";
				ans+=ba[i];
			}
			cout<<ans<<endl;
			continue;
		}
		if(pdB){
			for(int i=1;i<=n;i++){
				if(a[i][1]>=a[i][2]){
					ans+=a[i][1];
				}else {
					ans+=a[i][2];
				}
			}
			cout<<ans<<endl;
			continue;
		}
	}
	return 0;
}
