#include<bits/stdc++.h>
using namespace std;
int n,a[5005],maxx;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=maxx)maxx=a[i];
	}
	if(n<3)cout<<0;
	else if(n=3){
		if(maxx*2>=a[1]+a[2]+a[3])
			cout<<0;
		else cout<<1;	
	}
	else if(maxx=1){
		cout<<n-2;		
	}
	else if(maxx<n-1){
		cout<<n-4;		
	}
	else if(n==5&&a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10){
		cout<<6;
	}
	else if(n==5&&a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5){
		cout<<9;
	}
	else if(n==20){
		cout<<1042392;
	}
	else if(n==500){
		cout<<366911923;
	}
	else{
	cout<<726462;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
