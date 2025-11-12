#include<bits/stdc++.h>
using namespace std;
int n;
long long l[5010];
long long C(int n,int m){
	m=m>n/2?n-m:m;
	int a=1,b=1;
	for(int i=n;i>n-m;i--){
		a*=i;
	}
	for(int i=1;i<=m;i++){
		b*=i;
	}
	return a/b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	sort(l+1,l+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}else if(n==3){
		long long ss=l[1]+l[2]+l[3];
		if(ss>2*l[3]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else if(l[n]==1){
		
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans+=C(n,i);
			ans%=998244353;
		}
		cout<<ans;
		return 0;
		
	}else{
		
	}
	return 0;
}

