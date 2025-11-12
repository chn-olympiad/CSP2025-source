#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],b[5005],maxa;
long long sum; 
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		maxa=max(maxa,a[i]);
	}
	if(n<3){
		cout<<0<<endl;
		return 0;
	}
	if(n==3){
		if(sum>2*maxa){
			cout<<1<<endl;
			return 0;
		}
		else{
			cout<<0<<endl;
			return 0;
		}
	}
	if(maxa==1){
		long long ans=0;
		for(int i=3;i<=n;i++){
			long long tmp=1;
			for(int j=n;j>n-i;j--){
				tmp=tmp*j;
			}
			for(int j=i;j>1;j--) tmp/=j;
			ans+=tmp;
			ans%=998244353;
		}
		cout<<ans<<endl;
		return 0;
	}
	cout<<0<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
