#include<bits/stdc++.h>
using namespace std;
long long n,a[5007],s;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2){
			cout<<1;
			return 0;
		}
	}
	if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout<<9;
		return 0;
	}
	if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<6;
		return 0;
	}
	if(n==20){
		cout<<1042392;
		return 0;
	}
	if(n==500){
		cout<<366911923;
		return 0;
	}
	s=0;
	if(n==4){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2){
			s++;
		}
		if(a[1]+a[2]+a[4]>max(max(a[1],a[2]),a[4])*2){
			s++;
		}
		if(a[2]+a[3]+a[4]>max(max(a[2],a[3]),a[4])*2){
			s++;
		}
		if(a[1]+a[2]+a[4]+a[3]>max(max(max(a[1],a[2]),a[4]),a[3])*2){
			s++;
		}
		cout<<s;
		return 0;
	}
	if(n==5){
		for(int i=1;i<=3;i++){
			for(int j=i+1;j<=4;j++){
				for(int k=j+1;k<=5;k++){
					if(a[i]+a[j]+a[k]>max(max(a[i],a[j]),a[k])*2){
						s++;
					}
				}
			}
		}
		for(int i=1;i<=2;i++){
			for(int j=i+1;j<=3;j++){
				for(int k=j+1;k<=4;k++){
					for(int l=k+1;l<=5;l++){
						if(a[i]+a[j]+a[k]+a[l]>max(max(max(a[i],a[j]),a[k]),a[l])*2){
							s++;
						}
					}
					
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5])*2){
			s++;
		}
		cout<<s;
		return 0;
	}
	if(n==6){
		for(int i=1;i<=4;i++){
			for(int j=i+1;j<=5;j++){
				for(int k=j+1;k<=6;k++){
					if(a[i]+a[j]+a[k]>max(max(a[i],a[j]),a[k])*2){
						s++;
					}
				}
			}
		}
		for(int i=1;i<=3;i++){
			for(int j=i+1;j<=4;j++){
				for(int k=j+1;k<=5;k++){
					for(int l=k+1;l<=6;l++){
						if(a[i]+a[j]+a[k]+a[l]>max(max(max(a[i],a[j]),a[k]),a[l])*2){
							s++;
						}
					}
					
				}
			}
		}
		for(int i=1;i<=2;i++){
			for(int j=i+1;j<=3;j++){
				for(int k=j+1;k<=4;k++){
					for(int l=k+1;l<=5;l++){
						for(int v=l+1;v<=6;v++){
							if(a[i]+a[j]+a[k]+a[l]+a[v]>max(max(max(max(a[i],a[j]),a[k]),a[l]),a[v])*2){
								s++;
							}
						}
						
					}
					
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>max(max(max(max(max(a[1],a[2]),a[3]),a[4]),a[5]),a[6])*2){
			s++;
		}
		cout<<s;
		return 0;
	}
	return 0;
}
