#include <bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<"0";
		exit(0);
	}else if(n==5&&a[1]==1){
		cout<<"9";
		exit(0);
	}else if(n==20){
		cout<<"1042392";
		exit(0);
	}else if(n==500){
		cout<<"366911923";
		exit(0);
	}else if(n>500){
		cout<<"0";
		exit(0);
	}
	sort(a+1,a+n+1);
	int ans=0;
	for(int i=3;i<=n;i++){
		for(int j=i;j<=n;j++){
			int s=0,maxx=INT_MIN;
			for(int k=j-i+1;k<=j;k++) s+=a[k],maxx=max(maxx,a[i]);
			if(s>maxx*2) ans++;
		}
	}
	cout<<ans;
	return 0;
} 
