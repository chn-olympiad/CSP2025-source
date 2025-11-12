#include<bits/stdc++.h>
using namespace std;
const int N=5001;
int a[N],s[N],t[N],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[i]=a[i];
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n-3;i++){
		for(int j=i+2;j<=n;j++){
			int sum=s[j]-s[i-1],mx=0;
			for(int k=i;k<=j;k++)if(a[k]>mx)mx=a[k];
			if(sum > mx*2)ans++;
		}
	}
	cout<<ans%998244353;
	return 0;
}
