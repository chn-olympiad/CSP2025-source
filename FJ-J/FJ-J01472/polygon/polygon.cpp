#include<bits/stdc++.h>
using namespace std;
bool bigup(int x,int y){
	return x>y;
}
int jc(int n){
	long long s=1;
	for(int i=1;i<=n;i++){
		s*=i;
	}
	return s;
}
int c(int m,int n){
	return jc(m)/(jc(n)*jc(m-n));
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long n,l[5005],ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	sort(l+1,l+1+n,bigup);
	if(l[1]==1&&l[n]==1){
		for(int i=3;i<=n;i++){
			ans+=c(n,i);
			ans=ans%998244353;
		}
	}else if(n==3){
		if(l[1]+l[2]+l[3]>l[1]*3){
			ans=1;
		}
	}
	cout<<ans<<endl;
	return 0;
}
