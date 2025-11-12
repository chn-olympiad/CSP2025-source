#include<bits/stdc++.h>
using namespace std;
int n,a[10010],a1,maxa=-1,k;
long long x=1,y=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a1+=a[i];
		if(a[i]>maxa*2)maxa=a[i];
	}
	sort(a+1,a+1+n);
	if(n<=3){
		if(n<3)cout<<0;
		else if(a1>maxa)cout<<1;
	}
	else if(n==4){
		if(a1>maxa)k++;
		if(a[1]+a[2]>a[3])k++;
		if(a[1]+a[2]>a[4])k++;
		if(a[1]+a[3]>a[4])k++;
		if(a[2]+a[3]>a[4])k++;
		cout<<k;
	}
	else if(n==5){
		k=0;
		if(a1>maxa)k++;
		if(a[1]+a[2]+a[3]>a[4])k++;
		if(a[1]+a[2]+a[3]>a[5])k++;
		if(a[1]+a[2]+a[4]>a[5])k++;
		if(a[1]+a[3]+a[4]>a[5])k++;
		if(a[2]+a[3]+a[4]>a[5])k++;
		if(a[1]+a[2]>a[3])k++;
		if(a[2]+a[1]>a[4])k++;
		if(a[2]+a[1]>a[5])k++;
		if(a[1]+a[3]>a[4])k++;
		if(a[1]+a[3]>a[5])k++;
		if(a[4]+a[3]>a[5])k++;
		if(a[2]+a[4]>a[5])k++;
		if(a[2]+a[3]>a[5])k++;
		if(a[2]+a[3]>a[4])k++;
		if(a[1]+a[4]>a[5])k++;
		cout<<k;
	}
	else {
		k=0;
		for(int i=3;i<=n;i++){
			for(int j=n;j>=n-min(i,n-i)+1;j--){
				x*=j;
				x%=998244353;
			}
			for(int j=1;j<=min(i,n-i);j++){
				y*=j;
				y%=998244353;
			}	
			x/=y;
			x%=998244353;
			k+=x;
	}
		k%=998244353;
		cout<<k;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
