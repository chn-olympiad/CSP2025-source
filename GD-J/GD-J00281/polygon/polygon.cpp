#include<bits/stdc++.h>
using namespace std;
int n,a[5050];
long long ans;
void f(int s,int t,int m,int l){
	if(s>m*2 and t>3){
		ans++;
		ans%=998244353;
		if(t>n){
			return;
		}
	}
	for(int i=l+1;i<=n;i++){
		f(s+a[i],t+1,max(m,a[i]),i);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool t=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			t=false;
		}
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else if(t){
		ans=1;
		int nn=n;
		while(n>0){
			ans*=2;
			ans%=998244353;
			n--;
		}
		ans=ans-1-nn-nn*(nn-1)/2;
		ans%=998244353;
		cout<<ans;
	}
	else{
		f(0,1,0,0);
		cout<<ans;
	}
	return 0;
}
