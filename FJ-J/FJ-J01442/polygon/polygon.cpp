#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int a[N];
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int x=1;x<=3;x++){
		scanf("%d",&a[x]); 
	}
	if(n==3){
		if(a[1]+a[2]>a[3]&&a[2]+a[3]>a[1]&&a[1]+a[3]>a[2])cout<<1;
		else cout<<0;
	}
	else if(n==4){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					if(a[i]+a[j]>a[z]&&a[i]+a[z]>a[j]&&a[j]+a[z]>a[i])ans++;
				}
			}
		}
		if(a[1]+a[2]>a[4]&&a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[1]+a[3]>a[4]&&a[1]+a[4]>a[3]&&a[1]+a[4]>a[2]&&a[2]+a[3]>a[4]&&a[2]+a[3]>a[1]&&a[2]+a[4]>a[1]&&a[2]+a[4]>a[3]&&a[3]+a[4]>a[1]&&a[3]+a[4]>a[2])ans++;
		cout<<ans;
	}
	else if(n==5){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					if(a[i]+a[j]>a[z]&&a[i]+a[z]>a[j]&&a[j]+a[z]>a[i])ans++;
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int z=j+1;z<=n;z++){
					for(int v=z+1;v<=n;v++){
						if(a[i]+a[j]>a[v]&&a[i]+a[j]>a[z]&&a[i]+a[z]>a[j]&&a[i]+a[z]>a[v]&&a[i]+a[v]>a[z]&&a[i]+a[v]>a[j]&&a[j]+a[z]>a[v]&&a[j]+a[z]>a[i]&&a[j]+a[v]>a[i]&&a[j]+a[v]>a[z]&&a[z]+a[v]>a[i]&&a[z]+a[v]>a[j])ans++;
					}
				}
			}
		}
		if(a[1]+a[2]>a[4]&&a[1]+a[2]>a[3]&&a[1]+a[2]>a[5]&&a[1]+a[3]>a[2]&&a[1]+a[3]>a[4]&&a[1]+a[3]>a[5]&&a[1]+a[4]>a[2]&&a[1]+a[4]>a[3]&&a[1]+a[4]>a[5]&&a[1]+a[5]>a[2]&&a[1]+a[5]>a[3]&&a[1]+a[5]>a[4]&&a[2]+a[3]>a[4]&&a[2]+a[3]>a[1]&&a[2]+a[3]>a[5]&&a[2]+a[4]>a[5]&&a[2]+a[4]>a[1]&&a[2]+a[4]>a[3]&&a[2]+a[5]>a[1]&&a[2]+a[5]>a[3]&&a[2]+a[5]>a[4]&&a[3]+a[4]>a[5]&&a[3]+a[4]>a[1]&&a[3]+a[4]>a[2]&&a[3]+a[5]>a[1]&&a[3]+a[5]>a[2]&&a[3]+a[5]>a[4])ans++;
		cout<<ans;
	}
	return 0;
} 
