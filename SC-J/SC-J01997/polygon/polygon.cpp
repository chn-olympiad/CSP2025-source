#include<iostream>
#include<cstdio>
using namespace std;
int n,z[10000];
int p=3,da=-1,cnt,l=0;
long long int ans;
void go(){
	for(int k=p;k<=n;k++){
		da=-1,cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int q=j+1;q<=n;q++){
					int da1=max(z[i],z[j]);
					da=max(da,z[q]);
					da=max(da,da1); 
					cnt=z[i]+z[j]+z[q];
					if(da*2<cnt)ans++;
					ans=ans%998;
					ans=ans%244;
					ans=ans%353;
				}
			}
		}
	}
}
void go1(){
	ans=(1+n)*n/2-n-(n-1);
	ans=ans%998;
	ans=ans%244;
	ans=ans%353;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>z[i];
		if(z[i]!=1)l=1;
	}
	if(n<=3)go();
	else if(l==0)go1();
	cout<<ans;
	return 0;
} 