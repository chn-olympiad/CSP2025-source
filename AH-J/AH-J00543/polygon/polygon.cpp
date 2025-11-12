#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long a[5001];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(max(max(a[1],a[2]),a[3])*2<a[1]+a[2]+a[3])cout<<1;
		else cout<<0;
	}
	else{
		for(int i=1;i<=n;i++){
			ans+=i;
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
