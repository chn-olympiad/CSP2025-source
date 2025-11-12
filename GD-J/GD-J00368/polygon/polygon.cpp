#include<bits/stdc++.h>
using namespace std;
int n;
int a[5005];
int ans=0;
int g=0;
//int cmp(int x,int y){
//	return x>y; 
//}
int dg(int x){
	if(x>n){
		cout<<ans;
		return 0;
	}
//	int he=a[x];
	int he=0;
	for(int i=x+1;i<=n;i++){
		he=a[x]+a[i];
		
		for(int j=i+1;j<=n;j++){
			if(he>a[j]){
				ans++;
				for(int k=j+1;k<=n;k++){
					if(a[k]<he)ans++;
					else continue;
				}
//				for(int k=j+1;k<=n;k++){
//					if(he>a[k])ans++;
//					else continue;
//				}
			}
			he+=a[j];	
		} 
	}
	dg(x+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)g++;
	}
	if(n<=2){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2){
			cout<<1;
			return 0;
		}
	}
	if(g==n){
		cout<<n-2;
		return 0;
	}
	sort(a+1,a+n+1);
	dg(1);
	cout<<ans+1;
	return 0;
} 
