#include <bits/stdc++.h>
using namespace std;
long long n,a[5010],ans=0,s,m=-1; 

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n==3){
		s=a[1]+a[2]+a[3];
		if(s>a[3]*2)cout<<1;
		else cout<<0;
		return 0;
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i+2;j<=n;j++){
			for(long long k=i;k<=j;k++){
				s+=a[k];
				m=max(m,a[k]);
			}
			if(s>m*2)ans++;
		}
	}
	cout<<ans;
	return 0;

} 
