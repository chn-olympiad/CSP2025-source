#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans,mo=998244353;
void solve_3(){ 
	for(int i=3;i<=n;i++){
		int fz=1,fm=1;
		for(int j=1;j<=i;j++){
			fz*=(n-j+1); 
			fm*=j; 
		}
		ans+=fz/fm;
		ans%=mo;
	}
}
void solve_1(){
	int a[4],sum=0,maxx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		sum+=a[i];
	}
	if(sum>maxx*2) ans=1;
	else ans=0;
	return; 
}
void solve_2(){
	int a[11],sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(sum==n){
		solve_3();
		return;
	}
	for(int i=1;i<(2<<(n-1));i++){
		int k=i,cnt=0,sum=0,maxx=0;
		vector<int>b;
		for(int j=1;j<=n;j++){
			if(k%2==1){
				b.push_back(a[j]);
				cnt++;
				sum+=a[j];
				maxx=max(maxx,a[j]);
			}
			k/=2;
		}
		if(cnt<3) continue;
		if(sum>2*maxx){
			ans++;
			ans%=mo;
		}
	}
	return; 
}	
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		ans=0;
	}
	else if(n==3){
		solve_1(); 
	}
	else if(n<=20){
		solve_2(); 
	}
	else{
		solve_3();
	}
	cout<<ans;
	return 0;
}

