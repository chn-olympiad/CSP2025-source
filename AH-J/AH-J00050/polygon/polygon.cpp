#include<bits/stdc++.h>
using namespace std;
long long n,a[114514],sum[114514];
long long C(long long n,long long i){
	long long s1=1,s2=1,u1=n,u2=i;
	for(int j=0;j<i;j++){
		s1*=u1;
		s2*=u2;
		u1--;
		u2--;
		s1%=998244353;
		s2%=998244353;
	}
	return (s1/s2)%998244353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool p=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]&&i>1)p=false;
	}
	if(n==3){
		int y=max(max(a[1],a[2]),a[3]);
		if(y*2<a[1]+a[2]+a[3])cout<<1;
		else cout<<0;
	}else if(p==1){
		long long as=0;
		for(int i=3;i<=n;i++){
			as+=C(n,i)%998244353;
		//	cout<<C(n,i)<<endl;
		}
		cout<<as;
	}else if(n==4){
		long long as=0;
		int y=max(max(a[1],a[2]),a[3]);
		if(y*2<a[1]+a[2]+a[3])as++;
		y=max(max(a[2],a[4]),a[3]);
		if(y*2<a[2]+a[4]+a[3])as++;
		y=max(max(a[1],a[4]),a[3]);
		if(y*2<a[1]+a[4]+a[3])as++;
		y=max(max(a[1],a[2]),max(a[3],a[4]));
		if(y*2<a[1]+a[2]+a[3]+a[4])as++;
		cout<<as;
	}else if(n==5){
		long long as=0;
		int y=max(max(a[1],a[2]),a[3]);
		if(y*2<a[1]+a[2]+a[3])as++;
		y=max(max(a[1],a[2]),a[4]);
		if(y*2<a[2]+a[4]+a[1])as++;
		y=max(max(a[1],a[2]),a[5]);
		if(y*2<a[1]+a[2]+a[5])as++;
		y=max(max(a[1],a[3]),a[4]);
		if(y*2<a[1]+a[3]+a[4])as++;
		y=max(max(a[1],a[3]),a[5]);
		if(y*2<a[1]+a[3]+a[5])as++;
		y=max(max(a[1],a[4]),a[5]);
		if(y*2<a[1]+a[4]+a[5])as++;
		y=max(max(a[2],a[4]),a[3]);
		if(y*2<a[2]+a[4]+a[3])as++;
		y=max(max(a[2],a[3]),a[5]);
		if(y*2<a[2]+a[3]+a[5])as++;
		y=max(max(a[2],a[4]),a[5]);
		if(y*2<a[2]+a[4]+a[5])as++;
		y=max(max(a[3],a[4]),a[5]);
		if(y*2<a[3]+a[4]+a[5])as++;
		y=max(max(a[1],a[2]),max(a[3],a[4]));
		if(y*2<a[1]+a[2]+a[3]+a[4])as++;
		y=max(max(a[1],a[2]),max(a[3],a[5]));
		if(y*2<a[1]+a[2]+a[3]+a[5])as++;
		y=max(max(a[1],a[2]),max(a[4],a[5]));
		if(y*2<a[1]+a[2]+a[4]+a[5])as++;
		y=max(max(a[1],a[3]),max(a[4],a[5]));
		if(y*2<a[1]+a[3]+a[4]+a[5])as++;
		y=max(max(a[2],a[4]),max(a[3],a[5]));
		if(y*2<a[4]+a[2]+a[3]+a[5])as++;
		y=max(max(a[1],a[2]),max(a[3],max(a[4],a[5])));
		if(y*2<a[1]+a[2]+a[3]+a[5]+a[4])as++;
		cout<<as;
	}else{
		long long as=0;
		for(int i=3;i<=n;i++){
			as+=C(n,i)%998244353;
		//	cout<<C(n,i)<<endl;
		}
		cout<<as;   
	}
	return 0;
}
