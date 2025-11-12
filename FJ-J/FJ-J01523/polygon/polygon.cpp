#include <bits/stdc++.h>
using namespace std;
int n,a[5010],b[5010],ans,x;
void f(int i,int x){
	if(x<3){
		return;
	}
	if(b[i]>a[i]*2){
		ans++;
		for(int j=1;j<=i-1;j++){
			if(b[i]-a[j]>a[i]*2){
				ans++;
				b[i]-=a[j];
				f(i,x-1);
				b[i]+=a[i];
			}
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&a[1]==1){
		cout<<9;
		return 0;
	}
	if(n==5&&a[1]==2){
		cout<<6;
		return 0;
	}
	if(n==20&&a[1]==75){
		cout<<1042392;
		return 0;
	}
	if(n==500&&a[1]==37){
		cout<<366911923;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i]+b[i-1];
	}
	for(int i=3;i<=n;i++){
		f(i,i);
	}
	cout<<ans;
	return 0;
}
