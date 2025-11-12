#include<bits/stdc++.h>
using namespace std;
int a[5010];//12345
const int mod=998244353;
int n;//5
void f1() {
	int biggest=-1,all=0;
	for(int i=0; i<n; i++) {
		biggest=max(biggest,a[i]);
		all+=a[i];
	}
	cout<<(all>biggest*2)<<'\n'; 
}
int c(int n,int x){
	int ans1=1,ans2=1;
	for(int i=0;i<x;i++){
		ans1*=(n-i);
		ans2*=(x-i);
	}
	return ans1/ans2;
}
void f2(){
	long long ans=0;
	for(int i=3;i<=n;i++){
		ans=ans%mod+c(n,i)%mod;
	}
	cout<<ans<<'\n';
}
void f3(){
	int ans=0;//1111111
	sort(a,a+n);
	for(int i=0;i<n-2;i++){//3
		int num,cnt;
		for(int j=i+1;j<n-1;j++){
			num=a[i]+a[j];
			//3+4+5
			cnt=2;
			for(int z=j+1;z<n;z++){
				num+=a[z];
				cnt++;
				if(num>2*a[z]){
					ans++;
					cout<<i<<' '<<j<<' '<<z<<' ' ;
				}
				if(cnt>3){
					for(int b=j+1;b<z;b++){
						if(num-a[b]>2*a[z]){
							ans++;
							cout<<b<<'\n';
						}
					}
				}
				else{
					cout<<'\n';
				}
			}
		}
	}
	cout<<ans<<'\n';
}
int main() {
	freopen("polygon.in.txt","r",stdin);
	freopen("polygon.out.txt","w",stdout);
	cin>>n;
	int biggest=0;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		biggest=max(biggest,a[i]);
	}
	if(biggest==1){
		f2();
		return 0;
	}
	if(n<=3) {
		f1();
		return 0;
	}
	f3();
	return 0;
}
