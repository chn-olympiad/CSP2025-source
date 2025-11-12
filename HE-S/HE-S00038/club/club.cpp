#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;cin>>t;
	
	while(t--){
		int n;cin>>n;
		int a[10005],b[10005],c[10005],like[10005];
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if(a[i]>b[i]&&a[i]>c[i]){
				like[i]=1;
			}
			if(b[i]>a[i]&&b[i]>c[i]){
				like[i]=2;
			}
			if(c[i]>b[i]&&c[i]>a[i]){
				like[i]=3;
			}
		}	 
		
		//º∆À„
		int sum=0;
		int la=0,lb=0,lc=0;
		int lad[10005],lbd[10005],lcd[10005];
		for(int i=1;i<=n;i++){
			if(like[i]==1){
				la++;
				lad[la]=i;
			}
			if(like[i]==2){
				lb++;
				lbd[lb]=i;
			}
			if(like[i]==3){
				lc++;
				lcd[lc]=i;
			}
		}
		
		//«Û∫Õ 
		
		
		for(int i=1;i<=la;i++){
			sum+=a[lad[i]];
		}for(int i=1;i<=lb;i++){
			sum+=b[lbd[i]];
		}for(int i=1;i<=lc;i++){
			
			
			
			sum+=c[lcd[i]];
		}
	
		//≈≈≥˝ 
		
		if(la>n/2){
			for(int i=n/2;i<=la;i++){
				if(c[i]>b[i]&&lc<n/2){
					lcd[++lc]=i;
					sum=sum-a[i]+c[i];
				}else{
					lbd[++lb]=i;
					sum=sum-a[i]+b[i];
				}
			}
		}
		if(lb>n/2){
			for(int i=n/2;i<=lb;i++){
				if(a[i]>c[i]&&la<n/2){
					lad[++la]=i;
					sum=sum-b[i]+a[i];
				}else{
					lcd[++lc]=i;
					sum=sum-b[i]+c[i];
				}
			}
		}
		if(lc>n/2){
			for(int i=n/2;i<=lc;i++){
				if(a[i]>b[i]&&la<n/2){
					lad[++la]=i;
					sum=sum-c[i]+a[i];
				}else{
					lbd[++lb]=i;
					sum=sum-c[i]+b[i];
				}
			}
		}
		cout<<sum<<endl;
		sum=la=lb=lc=0;
	} 
	
	return 0;
}
