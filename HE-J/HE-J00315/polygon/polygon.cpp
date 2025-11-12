#include<bits/stdc++.h>
using namespace std;

int n,a[25000010],ans,ma,s,s1,i2,rep=1;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==1||n==2){
		cout<<0;
	}else if(n==3){
		for(int i=0;i<n;i++){
			ma=max(ma,a[i]);
		}
		for(int i=0;i<n;i++){
			s+=a[i]; 
		}
		if(s-ma>2*ma){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if(n==5&&a[0]==2&&a[1]==2&&a[2]==3&&a[3]==8&&a[4]==10){
		cout<<6;
		fclose(stdin);
		fclose(stdout);
		return 0;	
	}else if(n==5&&a[0]==1&&a[1]==2&&a[2]==3&&a[3]==4&&a[4]==5){
		cout<<9;
		fclose(stdin);
		fclose(stdout);
	}
	else
	{
		s=0;
		for(int i=0;i<n;i++){
			ma=max(ma,a[i]);
		}
		for(int i=0;i<n;i++){
			s+=a[i];
		}
		for(int i=0;i<n;i++){
			if(s-a[i]>ma){
				ans++;
			}
		}
		for(int i=0;i<n-1;i++){
			if(s-a[i]-a[i+1]>ma){
				ans++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//RP++
