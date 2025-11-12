#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,sum=0,ans=0,max=0;
	cin>>n;
	int a[5005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int m=3;m<=n;m++){
		for(int i=1;i<=n;i++){
			max=a[i];
			for(int j=i+1;j<=n;j++){
				if(a[j]>max) max=a[j];
				for(int k=j+1;k<=n;k++){
					if(a[k]>max) max=a[k];
					if(m==3){
						ans=a[i]+a[j]+a[k];
						if(ans>max*2) sum++;
					}
					for(int x=k+1;x<=n;x++){
						if(a[x]>max) max=a[x];
						if(m==4){
							ans=a[i]+a[j]+a[k]+a[x];
							if(ans>max*2) sum++;
						}
						for(int y=x+1;y<=n;y++){
							if(a[y]>max) max=a[y];
							if(m==5){
								ans=a[i]+a[j]+a[k]+a[x]+a[y];
								if(ans>max*2) sum++;
							}
						}
					}
				}
			}
		}
	}
	cout<<sum;
	return 0;
}
