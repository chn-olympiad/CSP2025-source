#include<bits/stdc++.h>
using namespace std;
int n,h,d;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<=2){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==3){
		int c=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					int ma1=max(a[i],a[j]);
					int ma2=max(a[k],a[j]);
					int mx=max(ma1,ma2);
					if((a[i]+a[j]+a[k])>mx*2){
						c++;
					}
				}
			} 
		}
		cout<<c;
	}
	if(n==4){
		int c=0,e=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					int ma1=max(a[i],a[j]);
					int ma2=max(a[k],a[j]);
					int mx=max(ma1,ma2);
					if((a[i]+a[j]+a[k])>mx*2){
						c++;
					}
				}
			} 
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						int ma1=max(a[i],a[j]);
						int ma2=max(a[k],a[l]);
						int mx=max(ma1,ma2);
						if((a[i]+a[j]+a[k]+a[l])>mx*2){
							e++;
						}
					}
				}
			}
		}
		cout<<c+e;
	}
	if(n==5){
		int c=0,e=0,f=0;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					int ma1=max(a[i],a[j]);
					int ma2=max(a[k],a[j]);
					int mx=max(ma1,ma2);
					if((a[i]+a[j]+a[k])>mx*2){
						c++;
					}
				}
			} 
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						int ma1=max(a[i],a[j]);
						int ma2=max(a[k],a[l]);
						int mx=max(ma1,ma2);
						if((a[i]+a[j]+a[k]+a[l])>mx*2){
							e++;
						}
					}
				}
			} 
		}
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				for(int k=j+1;k<n;k++){
					for(int l=k+1;l<n;l++){
						for(int m=l+1;m<n;m++){
							int ma1=max(a[i],a[j]);
							int ma2=max(a[k],a[l]);
							int ma3=max(ma1,ma2);
							int mx=max(ma3,a[m]);
							if((a[i]+a[j]+a[k]+a[l]+a[m])>mx*2){
								f++;
							}
						}
					}
				} 
			}
		}
		cout<<c+e+f;
	}
	return 0;
}
