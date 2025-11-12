#include<bits/stdc++.h>
using namespace std;
int n;
int a[5010];
int cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(a+b>c&&a+c>b&&b+c>a){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			cnt++;
		}
	}
	if(cnt==n){
		long long he=0;
		for(int i=3;i<=n;i++){
			long long shu=1;
			for(int j=n;j>=n-i+1;j--){
				shu*=j;
				shu%=998244353;
			}
			long long shu1=1;
			for(int o=1;o<=i;o++){
				shu1*=o;
				shu1%=998244353;
			}
			he+=shu/shu1;
			//cout<<shu<<" "<<shu1<<" "<<he<<endl;
			he%=998244353;
		}
		cout<<he;
		return 0;
	}
	return 0;
}
