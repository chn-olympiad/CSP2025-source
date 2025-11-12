#include<bits/stdc++.h>
using namespace std;
int t,n,sum,rs;
struct ar{
	int a1;
	int a2;
	int a3;
	int ma;
	int xz;
}a[100011];
int js[101];


int main(){
cin>>t;
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);

for(int z=1;z<=t;z++){
	rs=0;
	sum=0;
	js[1]=0;
	js[2]=0;
	js[3]=0;
	
	cin>>n;
	for(int i=1;i<=n;i++){
		a[i].a1=0;
		a[i].a2=0;
		a[i].a3=0;
		a[i].ma=0;
		a[i].xz=0;
	}
	
	
	for(int i=1;i<=n;i++){
		
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		
		a[i].ma=max(max(a[i].a1,a[i].a2),a[i].a3);
		
		if(a[i].ma==a[i].a1){
			a[i].xz=1;
		}
		
		else{
			if(a[i].ma==a[i].a2){
				a[i].xz=2;
				
			}
			
			else{
				a[i].xz=3;
			}
		}
	}

	for(int i=1;i<=n;i++){
		
	}

	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		if(a[i].ma>a[j].ma){
			swap(a[j],a[i]);
		}	
			
		}
		}
		
		
		for(int i=1;i<=n;i++){
			
			if(js[a[i].xz]<n/2){
				sum+=a[i].ma;
				++js[a[i].xz];
				
			
				
				}
				
			
				
				
				if(js[a[i].xz]==n/2){
				
					rs=1;
						if(a[i].xz==1){
							for(int j=i+1;j<=n;j++){
						a[j].ma=max(a[j].a3,a[j].a2);
						sum+=a[j].ma;
					}
					
				}
				else{
					if(a[i].xz==2){
						for(int j=i+1;j<=n;j++){
						a[j].ma=max(a[j].a1,a[j].a3);
						sum+=a[j].ma;
					}
					
					}
					
					else{
							for(int j=i+1;j<=n;j++){
						a[j].ma=max(a[j].a1,a[j].a2);
						sum+=a[j].ma;
					}
					}
					
				}	
				
				}
			if(rs==1)
			break;
		}
		
	cout<<sum;
	cout<<endl;
}
return 0;
}
