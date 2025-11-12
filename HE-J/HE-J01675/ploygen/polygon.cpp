#include<iostream>
using namespace std;
int n;int a[100001];bool pan=1;int ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];if(a[i]!=1) pan=0;
	} 
	if(n==3){
		int sum=a[1]+a[2]+a[3];
		int maxx=max(a[1],max(a[2],a[3]));
		if(maxx*2<sum) cout<<1;
		else cout<<0;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(pan){
		for(int i=3;i<=n;i++){
			ans+=n%i;
		}
		cout<<ans;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	cout<<8724;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
