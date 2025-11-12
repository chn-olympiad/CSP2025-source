#include<bits/stdc++.h>
using namespace std;
int a[100010];
int f[1010][1010];
int sum,cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//1:Ñ¡£¬2£º²»Ñ¡ 
	int maxn=0;
	if(n==3){
		for(int i=1;i<=2;i++){
			if(i==1){
				sum+=a[i];
				maxn=max(maxn,a[i]);	
			}
			for(int j=1;j<=2;j++){
				if(j==1){
					sum+=a[i];
					maxn=max(maxn,a[i]);	
				}
				if(sum>maxn*2)  cnt++;
				sum=0;
				maxn=0;
			}
		}
	}
	if(n==4){
		for(int i=1;i<=2;i++){
			if(i==1){
				sum+=a[1];
				maxn=max(maxn,a[1]);	
			}
			for(int j=1;j<=2;j++){
				if(j==1){
					sum+=a[2];
					maxn=max(maxn,a[2]);	
				}
				for(int k=1;k<=2;k++){
					if(k==1){
						sum+=a[3];
						maxn=max(maxn,a[3]);	
					}
					for(int y=1;y<=2;y++){
						if(y==1){
							sum+=a[4];
							maxn=max(maxn,a[4]);
						}
						if(sum>maxn*2)  cnt++;
						sum=0;
						maxn=0;
					}
				}
			}
		}
	}
	if(n==5){
		for(int i=1;i<=2;i++){
			if(i==1){
				sum+=a[1];
				maxn=max(maxn,a[1]);	
			}
			for(int j=1;j<=2;j++){
				if(j==1){
					sum+=a[2];
					maxn=max(maxn,a[2]);	
				}
				for(int k=1;k<=2;k++){
					if(k==1){
						sum+=a[3];
						maxn=max(maxn,a[3]);	
					}
					for(int y=1;y<=2;y++){
						if(y==1){
							sum+=a[4];
							maxn=max(maxn,a[4]);
						}
						for(int z=1;z<=2;z++){
							if(z==1){
								sum+=a[5];
								maxn=max(maxn,a[5]);
							}
							if(sum>maxn*2)  cnt++;
							sum=0;
							maxn=0;
						}
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}


