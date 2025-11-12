#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[5002]={},s[5002]={};
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int ans=0;
	if(n<=3){
		if(a[1]+a[2]>a[3])ans++;
		cout<<ans;
	}else{
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}