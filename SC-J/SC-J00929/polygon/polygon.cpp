#include<bits/stdc++.h>
using namespace std;

const int N=5e3+5;

int n,a[N],num[N],ans;

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num[i]=num[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	if(num[n]>2*a[n]&&n==3) cout<<'1';
	if(num[n]<=2*a[n]&&n==3) cout<<'0';
	if(a[n]==1){
		for(int i=3;i<=n;i++){
			ans+=(i)*(i-1)*(i-2)/6;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}