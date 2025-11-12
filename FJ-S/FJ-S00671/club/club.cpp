#include<bits/stdc++.h>
using namespace std;
#define int long long
	int a[1000086][7];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int x[5]={0,0,0,0,0};
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
				a[i][j+3]=0;
			}
			int mx=max(a[i][1],max(a[i][2],a[i][3]));
			bool flag=1;
			for(int j=1;j<=3;j++){
				if(flag&&a[i][j]==mx){
					a[i][4]=j;
					x[j]++;
					flag=0;
					continue;
				}
				a[i][j]=mx-a[i][j];
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i][a[i][4]];
//			cout<<i<<"："<<a[i][a[i][4]]<<endl; 
		}
//		cout<<"总："<<ans;
		int kun[4]={1,1,1},iiff=0;
		for(int j=1;j<=3;j++){
			if(iiff){
				kun[j]=0;
			}
			while(x[j]>n/2){
				iiff=1;
//				cout<<"因为：x["<<j<<"]>"<<n/2<<endl; 
				int mni,mnj,mn=INT_MAX,wei;
				for(int i=1;i<=n;i++){
					int smnj,smn=INT_MAX,swei;
					bool f=1;
					if(a[i][5]==j){
						smnj=6-a[i][4]-a[i][5];
						smn=a[i][smnj];
						swei=6;
						
						f=0;
					} 
					if(a[i][4]==j&&a[i][5]==0){
						for(int l=1;l<=3;l++){
							if(a[i][4]!=l){
								if(smn>a[i][l]){
									smnj=l;
									smn=a[i][l];
									swei=5;
								}
							}
						}
					}
					if(smn<mn){
						mn=smn;
						mni=i;
						mnj=smnj;
						wei=swei;
					}
				}
				if(wei==6){
					x[j]--;
					a[mni][6]=mnj;
					x[mnj]++;
//					cout<<"(6)ans=" <<ans; 
					ans=ans-a[mni][a[mni][6]]+a[mni][a[mni][5]];
//					cout<<"-"<<a[mni][a[mni][6]]<<"+"<<a[mni][a[mni][5]]<<"="<<ans<<"   (mni="<<mni<<")"<<endl;
				}
				else{
					x[j]--;
				a[mni][5]=mnj;
				x[mnj]++;
//				cout<<"(5)ans=" <<ans; 
				ans=ans-a[mni][a[mni][5]];
//				cout<<"-"<<a[mni][a[mni][5]]<<"="<<ans<<"   (mni="<<mni<<")"<<endl;
				}
				
				
			}
			
		}
		for(int j=1;j<=3;j++){
			if(kun[j]){
			while(x[j]>n/2){
				iiff=1;
//				cout<<"因为：x["<<j<<"]>"<<n/2<<endl; 
				int mni,mnj,mn=INT_MAX,wei;
				for(int i=1;i<=n;i++){
					int smnj,smn=INT_MAX,swei;
					bool f=1;
					if(a[i][5]==j){
						smnj=6-a[i][4]-a[i][5];
						smn=a[i][smnj];
						swei=6;
						
						f=0;
					} 
					if(a[i][4]==j){
						for(int l=1;l<=3;l++){
							if(a[i][4]!=l){
								if(smn>a[i][l]){
									smnj=l;
									smn=a[i][l];
									swei=5;
								}
							}
						}
					}
					if(smn<mn){
						mn=smn;
						mni=i;
						mnj=smnj;
						wei=swei;
					}
				}
				if(wei==6){
					x[j]--;
					a[mni][6]=mnj;
					x[mnj]++;
//					cout<<"(6)ans=" <<ans; 
					ans=ans-a[mni][a[mni][6]]+a[mni][a[mni][5]];
//					cout<<"-"<<a[mni][a[mni][6]]<<"+"<<a[mni][a[mni][5]]<<"="<<ans<<"   (mni="<<mni<<")"<<endl;
				}
				else{
					x[j]--;
				a[mni][5]=mnj;
				x[mnj]++;
//				cout<<"(5)ans=" <<ans; 
				ans=ans-a[mni][a[mni][5]];
//				cout<<"-"<<a[mni][a[mni][5]]<<"="<<ans<<"   (mni="<<mni<<")"<<endl;
				}
				
			}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}//3 2 10 9 8 4 0 0 4 4 2 1 3 2 4 5 3 4 3 5 1 4 0 1 0 0 1 0 0 2 0 0 2 0  
