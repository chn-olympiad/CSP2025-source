#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000],ans=0;
int lmh(int x){
	int f=1;
	for(int i=x-1;i>=0;i--){
		long an=a[i];
		for(int j=i-1;j>=0;j--){
			an+=a[j];
			if(an>a[x]){
				ans=ans+1+j;f=0;break;
			}
		}
		if(f==1){
			break;
		}
		else{
			f=1;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n<3){
		cout<<0;return 0;
	}
	if(n==3){
		if(a[0]+a[1]>a[2]){
			cout<<1;return 0;
		}
		else{
			cout<<0;return 0;
		}
	}
	for(int i=n-1;i>=0;i--){
		lmh(i);
	}
	cout<<(ans/2*3)%998244353;
	return 0;
}

