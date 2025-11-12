#include<bits/stdc++.h>
using namespace std;
int n,ans=0,maxx=INT_MIN;
int a[5010],b[5010];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	maxx=b[n]*2;
	for(int i=1;i<=n;i++){
		if(n=4){
			if(a[i]+a[i+1]+a[i+2]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]>maxx)ans++;
		}
		if(n==5){
			if(a[i]+a[i+1]+a[i+2]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]>maxx)ans++;
		}
		if(n==6){
			if(a[i]+a[i+1]+a[i+2]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]>maxx)ans++;
		}
		if(n==7){
			if(a[i]+a[i+1]+a[i+2]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]>maxx)ans++;
		}
		if(n==8){
			if(a[i]+a[i+1]+a[i+2]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]>maxx)ans++;
		}
		if(n==9){
			if(a[i]+a[i+1]+a[i+2]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+a[i+8]>maxx)ans++;
		}
		if(n==10){
			if(a[i]+a[i+1]+a[i+2]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+a[i+8]>maxx)ans++;
			if(a[i]+a[i+1]+a[i+2]+a[i+3]+a[i+4]+a[i+5]+a[i+6]+a[i+7]+a[i+8]+a[i+9]>maxx)ans++;
		}
	}
	cout<<ans;
	return 0;
}
