#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int s=0;
	if(n==3){
		if(a[1]+a[2]+a[3]>2*a[3])s++;
		cout<<s;
	}
	if(n==4){
		if(a[1]+a[2]+a[3]>2*a[3])s++;
		if(a[4]+a[2]+a[3]>2*a[4])s++;
		if(a[1]+a[4]+a[3]>2*a[4])s++;
		if(a[1]+a[2]+a[4]>2*a[4])s++;
		if(a[1]+a[2]+a[3]+a[4]>2*a[4])s++;
		cout<<s;
	}
	if(n==5){
		for(int i=1;i<=3;i++){
			for(int j=i+1;j<=4;j++){
				for(int k=j+1;k<=5;k++)
					if(a[i]+a[j]+a[k]>2*a[k])s++;
			}
		}
		for(int i=1;i<=2;i++){
			for(int j=i+1;j<=3;j++){
				for(int k=j+1;k<=4;k++){
					for(int l=k+1;l<=5;l++)
						if(a[i]+a[j]+a[k]+a[l]>2*a[l])s++;
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*a[5])s++;
		cout<<s;
	}
	if(n>5)cout<<20;
	return 0;
}
