#include<bits/stdc++.h>
using namespace std;
int n,sum1=0,i,j,k,l,a[6],maxa=0,ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		for(i=1;i<=3;i++){
			sum1+=a[i];
			if(a[i]>maxa) maxa=a[i];
		}
		if(sum1>maxa*2) cout<<1;
		else cout<<0;
	}
	if(n==4){
		for(i=1;i<=2;i++){
			sum1+=a[i];
			for(j=i+1;j<=3;j++){
				sum1+=a[j];
				for(k=j+1;k<=4;k++){
					sum1+=a[k];
					if(sum1>max(a[i],max(a[j],a[k]))*2) {
					ans++;}
					sum1-=a[k];
				}
				sum1-=a[j];
			}
			sum1-=a[i];
		}
		sum1=0;
		for(i=1;i<=4;i++){
			sum1+=a[i];
			if(a[i]>maxa) maxa=a[i];
		}
		if(sum1>maxa*2) ans++;
		cout<<ans;
	}
	if(n==5){
		for(i=1;i<=3;i++){
			sum1+=a[i];
			for(j=i+1;j<=4;j++){
				sum1+=a[j];
				for(k=j+1;k<=5;k++){
					sum1+=a[k];
					if(sum1>max(a[i],max(a[j],a[k]))*2) {
					ans++;}
					sum1-=a[k];
				}
				sum1-=a[j];
			}
			sum1-=a[i];
		}
		for(i=1;i<=2;i++){
			sum1+=a[i];
			for(j=i+1;j<=3;j++){
				sum1+=a[j];
				for(k=j+1;k<=4;k++){
					sum1+=a[k];
					for(l=k+1;l<=5;l++){
						sum1+=a[l];
						if(sum1>max(a[i],max(a[j],max(a[l],a[k])))*2) {
							ans++;}
						sum1-=a[l];
					}
					sum1-=a[k];
				}
				sum1-=a[j];
			}
			sum1-=a[i];
		}
		sum1=0;
		for(i=1;i<=5;i++){
			sum1+=a[i];
			if(a[i]>maxa) maxa=a[i];
		}
		if(sum1>maxa*2) ans++;
		cout<<ans;
	}
	return 0;
}
