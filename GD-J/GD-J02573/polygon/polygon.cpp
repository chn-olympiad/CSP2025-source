#include<bits/stdc++.h>
using namespace std;
int n,a[5011],ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
		for(int j=i+3;j<n;j++){
			int sum=0;
			for(int o=i;o<=j;o++) sum+=a[o];
			if(sum>j*2) ans++;
		}
	cout<<ans%998244353;
	return 0;
}
