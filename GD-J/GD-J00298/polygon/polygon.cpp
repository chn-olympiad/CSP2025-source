#include<bits/stdc++.h>
#define  ll long long
using namespace std;
//void dfs(){
//	if()
//}
ll n,a[100001],ans,sb;
int main(){
	ios::sync_with_stdio();
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sb+=a[i];
	}
	if(sb>a[n]*2){
		ans++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				ans%=998,244,353;
//				cout<<a[i]<<" "<<a[j]<<" "<<a[k] <<endl;		
				if(a[i]+a[j]+a[k]>a[k]*2){
					ans++;
					ans%=998,244,353;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int s=k+1;s<=n;s++){
					ans%=998,244,353;
//						cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[s]<<" "<<endl;					
					if(a[i]+a[j]+a[k]+a[s]>a[s]*2){

						ans++;
						ans%=998,244,353;
					}
				}
			}
		}
	}
	if(n==5){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int s=k+1;s<=n;s++){
					for(int sb=s+1;sb<=n;sb++){
						ans%=998,244,353;
//						cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[s]<<" "<<endl;					
					if(a[i]+a[j]+a[k]+a[s]+a[sb]>a[sb]*2){

						ans++;
						ans%=998,244,353;
					}
					}
				}
			}
		}
	}if(n==6){
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				for(int s=k+1;s<=n;s++){
					for(int sb=s+1;sb<=n;sb++){
						for(int s1=sb+1;s1<=n;s1++){
							ans%=998,244,353;
//						cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[s]<<" "<<endl;					
						if(a[i]+a[j]+a[k]+a[s]+a[sb]+a[s1]>a[s1]*2){

								ans++;
								ans%=998,244,353;
							}
						}
						
					}
					
				}
			}
		}
	}
	if(n==7){
		cout<<ans;
		return 0;
	}
	
	return 0;
}	


