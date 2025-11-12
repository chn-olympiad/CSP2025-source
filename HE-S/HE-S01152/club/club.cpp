#include<bits/stdc++.h>
using namespace std;
int t,n;
int az,bz,cz;
int a[50001];
int b[50001];
int c[50001];
int max1;
int ans=0;
int z[50001];
int sc[50001];
int cm[50001];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		
		for(int j=1;j<=n;j++){
			cin>>a[j]>>b[j]>>c[j];
		}
			for(int j=1;j<=n;j++){
			if((a[j]>b[j]||a[j]==b[j])&&(b[j]>c[j]||b[j]==c[j])){
				 sc[j]=a[j]-b[j];
				 cm[j]=b[j]-c[j];
				 z[j]=1;
			}
			if((a[j]>c[j]||a[j]==c[j])&&(c[j]>b[j]||b[j]==c[j])){
				 sc[j]=a[j]-c[j];
				 cm[j]=c[j]-b[j];
				 z[j]=2;
			}
			if((b[j]>a[j]||a[j]==b[j])&&(a[j]>c[j]||a[j]==c[j])){
				 sc[j]=b[j]-a[j];
				 cm[j]=a[j]-c[j];
				 z[j]=3;
			}
			if((b[j]>c[j]||b[j]==c[j])&&(c[j]>a[j]||c[j]==a[j])){
				 sc[j]=b[j]-c[j];
				 cm[j]=c[j]-a[j];
				 z[j]=4;
			}
			if((c[j]>a[j]||c[j]==a[j])&&(a[j]>b[j]||a[j]==b[j])){
				 sc[j]=c[j]-a[j];
				 cm[j]=a[j]-b[j];
				 z[j]=5;
			}
			if((c[j]>b[j]||c[j]==b[j])&&(b[j]>a[j]||b[j]==a[j])){
				 sc[j]=c[j]-b[j];
				 cm[j]=b[j]-a[j];
				 z[j]=6;
			}
			}
			
			for(int y=1;y<=n;y++){
				max1=0;
				for(int j=1;j<=n;j++){
				
				if(max1<sc[j]){
					max1=sc[j];
				}
			}
			for(int j=1;j<=n;j++){
				if(max1==0){
					j=n+1;
				}
				if(max1==sc[j]&&sc[j]!=0){
					if(z[j]==1||z[j]==2){
						if(az<n/2){
						az++;
						ans+=a[j];
						sc[j]=0;
						cm[j]=0;
						}
					}
					if(z[j]==3||z[j]==4){
						if(bz<n/2){
						bz++;
						ans+=b[j];
						sc[j]=0;
						cm[j]=0;
						}
					}
					if(z[j]==5||z[j]==6){
						if(cz<n/2){
						cz++;
						ans+=c[j];
						sc[j]=0;
						cm[j]=0;
						}
					}
				}
				
			}
		}//1
		
			
			for(int y=1;y<=n;y++){
				max1=0;
				for(int j=1;j<=n;j++){
				
				if(max1<cm[j]){
					max1=cm[j];
				}
			}
			for(int j=1;j<=n;j++){
				
				if(max1==cm[j]&&cm[j]!=0){
					if(z[j]==1||z[j]==6){
						if(bz<n/2){
						bz++;
						ans+=b[j];
						cm[j]=0;
						}
					}
					if(z[j]==2||z[j]==4){
						if(cz<n/2){
						cz++;
						ans+=c[j];
						cm[j]=0;
						}
					}
					if(z[j]==5||z[j]==3){
						if(az<n/2){
						az++;
						ans+=a[j];
						cm[j]=0;
						}
					}
				}
				
			}
			for(int j=1;j<=n;j++){
				
				if(cm[j]!=0){
					if(z[j]==1||z[j]==3){
						
						cz++;
						ans+=c[j];
					}
					if(z[j]==2||z[j]==5){
						bz++;
						ans+=b[j];
					}
					if(z[j]==4||z[j]==6){
						
						az++;
						ans+=a[j];
						
					}
				}
				
			}
		}
			cout<<ans;
			ans=0;
		az=0;
		bz=0;
		cz=0;//	
		
	}
	
	
	
	fclose(stdin);
	fclose(stdout);
	
	return 0; 
}
