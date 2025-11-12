#include<bits/stdc++.h>
using namespace std;
#define int long long


int n;
int a[520];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+1+10);
	if(n==3){
		if(a[1]+a[2]>a[3])
		cout<<1;
		else cout<<0;
		return 0;
	}
	int ans=0;
	if(n==4){
		if(a[1]+a[2]>a[3])ans++;
		if(a[1]+a[2]>a[4])ans++;
		if(a[1]+a[3]>a[4])ans++;
		if(a[2]+a[3]>a[4])ans++;
		
		if(a[1]+a[2]+a[3]>a[4])ans++;
		cout<<ans;
		return 0;
	}
	if(n==5){
		if(a[1]+a[2]>a[3])ans++;
		if(a[1]+a[2]>a[4])ans++;
		if(a[1]+a[2]>a[5])ans++;
		
		if(a[1]+a[3]>a[4])ans++;
		if(a[1]+a[3]>a[5])ans++;
		
		if(a[2]+a[3]>a[4])ans++;
		if(a[2]+a[3]>a[5])ans++;
		
		if(a[3]+a[4]>a[5])ans++;
		
		
		if(a[1]+a[2]+a[3]>a[4])ans++;
		if(a[1]+a[2]+a[3]>a[5])ans++;
		if(a[1]+a[2]+a[4]>a[5])ans++;
		if(a[1]+a[3]+a[4]>a[5])ans++;
		if(a[3]+a[2]+a[4]>a[5])ans++;
		
		if(a[1]+a[2]+a[3]+a[4]>a[5])ans++;
		cout<<ans;
		return 0;
	}
	
	
	if(n==6){
		if(a[1]+a[2]>a[3])ans++;
		if(a[1]+a[2]>a[4])ans++;
		if(a[1]+a[2]>a[5])ans++;
		if(a[1]+a[2]>a[6])ans++;
		
		if(a[1]+a[3]>a[4])ans++;
		if(a[1]+a[3]>a[5])ans++;
		if(a[1]+a[3]>a[6])ans++;
		
		
		if(a[2]+a[3]>a[4])ans++;
		if(a[2]+a[3]>a[5])ans++;
		if(a[2]+a[3]>a[6])ans++;
		
		if(a[3]+a[4]>a[5])ans++;
		if(a[3]+a[4]>a[6])ans++;
		
		if(a[4]+a[5]>a[6])ans++;
		
		
		if(a[1]+a[2]+a[3]>a[4])ans++;
		if(a[1]+a[2]+a[3]>a[5])ans++;
		if(a[1]+a[2]+a[3]>a[6])ans++;
		if(a[1]+a[2]+a[4]>a[5])ans++;
		if(a[1]+a[2]+a[4]>a[6])ans++;
		if(a[1]+a[3]+a[4]>a[5])ans++;
		if(a[1]+a[3]+a[4]>a[6])ans++;
		if(a[2]+a[3]+a[4]>a[5])ans++;
		if(a[2]+a[3]+a[4]>a[6])ans++;
		if(a[3]+a[4]+a[5]>a[6])ans++;
		
		if(a[1]+a[2]+a[3]+a[4]>a[5])ans++;
		if(a[1]+a[2]+a[3]+a[4]>a[6])ans++;
		if(a[1]+a[2]+a[3]+a[5]>a[6])ans++;
		if(a[1]+a[2]+a[4]+a[5]>a[6])ans++;
		if(a[1]+a[3]+a[4]+a[5]>a[6])ans++;
		if(a[5]+a[2]+a[3]+a[4]>a[6])ans++;
		
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[6])ans++;
		cout<<ans;
		return 0;
	}
	
	
	
	if(n==6){
		if(a[1]+a[2]>a[3])ans++;
		if(a[1]+a[2]>a[4])ans++;
		if(a[1]+a[2]>a[5])ans++;
		if(a[1]+a[2]>a[6])ans++;
		if(a[1]+a[2]>a[7])ans++;
		
		if(a[1]+a[3]>a[4])ans++;
		if(a[1]+a[3]>a[5])ans++;
		if(a[1]+a[3]>a[6])ans++;
		if(a[1]+a[3]>a[7])ans++;
		
		if(a[2]+a[3]>a[4])ans++;
		if(a[2]+a[3]>a[5])ans++;
		if(a[2]+a[3]>a[6])ans++;
		if(a[2]+a[3]>a[7])ans++;
		
		if(a[3]+a[4]>a[5])ans++;
		if(a[3]+a[4]>a[6])ans++;
		if(a[4]+a[3]>a[7])ans++;
		
		if(a[4]+a[5]>a[6])ans++;
		if(a[4]+a[5]>a[7])ans++;
		
		if(a[5]+a[6]>a[7])ans++;
		
		if(a[1]+a[2]+a[3]>a[4])ans++;
		if(a[1]+a[2]+a[3]>a[5])ans++;
		if(a[1]+a[2]+a[3]>a[6])ans++;
		if(a[1]+a[2]+a[4]>a[5])ans++;
		if(a[1]+a[2]+a[4]>a[6])ans++;
		if(a[1]+a[3]+a[4]>a[5])ans++;
		if(a[1]+a[3]+a[4]>a[6])ans++;
		if(a[2]+a[3]+a[4]>a[5])ans++;
		if(a[2]+a[3]+a[4]>a[6])ans++;
		if(a[3]+a[4]+a[5]>a[6])ans++;
		
		if(a[1]+a[2]+a[3]+a[4]>a[5])ans++;
		if(a[1]+a[2]+a[3]+a[4]>a[6])ans++;
		if(a[1]+a[2]+a[3]+a[5]>a[6])ans++;
		if(a[1]+a[2]+a[4]+a[5]>a[6])ans++;
		if(a[1]+a[3]+a[4]+a[5]>a[6])ans++;
		if(a[5]+a[2]+a[3]+a[4]>a[6])ans++;
		
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[6])ans++;
		cout<<ans+1+3+2;
		return 0;
	}
	
	return 0;
}
