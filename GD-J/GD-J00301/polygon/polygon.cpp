#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int n;
int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];		
	}
	if(n<3)cout<<0;
	if(n==3){
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]){
			ans++;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
} 
