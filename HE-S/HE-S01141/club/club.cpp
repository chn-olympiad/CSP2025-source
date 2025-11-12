#include <bits/stdc++.h>
using namespace std;
struct fen{
	int q,w,e;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		int sum=0;
		fen a[10000+5];
		fen b[10000+5];
		fen c[10000+5];
		int f=0;
		int ma=0;
		for(int i=0;i<n;i++){
			cin>>a[i].q>>b[i].w>>c[i].e;
		}
		for(int j=0;j<n/2;j++){
			for(int i=0;i<n;i++){
				if(a[i].q>ma){
					f=a[i].q;			
				}
			}sum+=f;
			for(int i=0;i<n;i++){
				if(sum==a[i]){
					a[i]=0;
				}
			}	
	 }cout<<sum<<endl;
	 f=0;
		for(int j=0;j<n/2;j++){
			for(int i=0;i<n;i++){
				if(a[i].w>ma){
					f=a[i].w;
				}
			}sum+=f;
			for(int i=0;i<n;i++){
				if(sum==a[i]){
					a[i]=0;
				}
			}
					
	 	}cout<<sum<<endl;
	 	f=0;
		for(int j=0;j<n/2;j++){
			for(int i=0;i<n;i++){
				if(a[i].e>ma){
					f=a[i].e;	
				}
			}
			sum+=f;
			for(int i=0;i<n;i++){
				if(sum==a[i]){
					a[i]=0;
				}
			}
		}cout<<sum;
	}
	return 0;
}

