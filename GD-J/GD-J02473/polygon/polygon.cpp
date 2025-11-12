#include<bits/stdc++.h>
using namespace std;
int n;
int a[5050];
long long ans=0;
bool flag=1;
int max0(int n,int a[]){
	int s=0;
	for(int i=1;i<=n;i++){
		if(s<a[i]) s=a[i];
	}
	return s;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3) {
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n-1;i++){
		if(a[i]!=a[i+1]) flag=0;
	}
	if(flag){
		cout<<n-2;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max0(3,a)){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(n==4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))){
						ans++;
					}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]>2*max0(4,a)) ans++;
		cout<<ans;
		return 0;
	}
	
	
	
	
	
	
	if(n==5){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(a[i]+a[j]+a[k]>2*max(a[i],max(a[j],a[k]))){
						ans++;
					}
				}
			}
		}for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					for(int l=k+1;l<=n;l++)
						if(a[i]+a[j]+a[k]+a[l]>2*max(a[i],max(a[j],max(a[k],a[l])))){
							ans++;
						}
				}
			}
		}
		if(a[1]+a[2]+a[3]+a[4]+a[5]>2*max0(5,a)) ans++;
		cout<<ans;
		return 0;
	}
	return 0;
}

