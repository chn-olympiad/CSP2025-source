#include<bits/stdc++.h>
using namespace std;
//pts- 55
const long long mods =  998244353;
int a[5001];
int n;
long long counts=0;
void xz(int u,int g,int mas,long long plus){
	if(g>=3 and plus>mas*2){
		counts=counts+1;
		counts%=mods;
	}
	for(int i=u+1;i<n;i++){
		//cout<<i<<" "<<g+1<<" "<<max(mas,a[i])<<" "<<plus+a[i];
		xz(i,g+1,max(mas,a[i]),plus+a[i]);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool all1=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1) all1=false;
	} 
	if(all1){
		long long ans=1;
		for(int i=n-2;i>=2;i--){
			long long pres=1;
			for(int j=i+1;j<=n;j++){
				pres*=i;
				pres%=mods;
			}
			ans+=pres;
			ans%=mods;
		}
		cout<<ans;
	}
	else{
		for(int i=0;i<n-2;i++){
			xz(i,1,a[i],a[i]);
		}
		cout<<counts;
	}
	
	return 0;
} 

