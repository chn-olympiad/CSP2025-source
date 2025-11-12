#include<bits/stdc++.h>
using namespace std;
int n,num,maxnn;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	long long a[n+1];
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	else if(n==3){
		if(a[i]+a[2]=2*a[3]){
			cout<<1;
			return 0;
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else{
		if(n==4){
			if(a[1]+a[2]>2*a[3]) num++;
			if(a[1]+a[3]>2*a[4]) num++;
			if(a[2]+a[3]>2*a[4]) num++;
		}
		if(n==5){
			if(a[1]+a[2]>2*a[3]) num++;
			if(a[1]+a[2]>2*a[4]) num++;
			if(a[1]+a[2]>2*a[5]) num++;
			if(a[1]+a[3]>2*a[4]) num++;
			if(a[1]+a[3]>2*a[5]) num++;
			if(a[2]+a[3]>2*a[4]) num++;
			if(a[2]+a[3]>2*a[5]) num++;
			if(a[1]+a[2]+a[3]>2*a[4]) num++;
			if(a[2]+a[3]+a[4]>2*a[5]) num++;
			if(a[1]+a[2]+a[3]+a[4]>2*a[5]) num++;
		}
		else{
			cout<<2*n-1;
			return 0;
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
