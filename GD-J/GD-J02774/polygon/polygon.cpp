#include<bits/stdc++.h>
using namespace std;
int n,a[5005],v[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[i]=a[i]+v[i-1];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(a+1,a+1+n);
	int maxn=a[n];
	if(v[n]>=maxn*2) ans++;
	if(n==3){
		if(a[1]+a[2]+a[3]>=maxn*2){
			cout<<1;
			return 0;
		}
	}
	int hc=n-1;
	int j=1;
	while(hc>=3){
		if(j-1+hc<=n){
			maxn=a[j-1+hc];
			if(v[j-1+hc]-v[j-1]>=maxn*2){
				ans++;
				j++;
			} 
		}else{
			j=1;
			hc--;
		}
	}
	cout<<ans;
	return 0;
}
