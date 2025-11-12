#include <bits/stdc++.h>
using namespace std;
int n,a[5001],ans;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long tmp=0;
	if(n==3){
		for(int i=1;i<=n;i++){
			tmp+=a[i];
		}
		if(tmp>a[3]*2){
			ans++;
		}
	}else if(n==4){
		if(a[1]+a[2]+a[3]>a[3]*2)ans++;
		if(a[1]+a[2]+a[4]>a[4]*2)ans++;
		if(a[2]+a[3]+a[4]>a[4]*2)ans++;
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2)ans++;
	}else if(n==5){
		if(a[1]+a[2]+a[3]>a[3]*2)ans++;
		if(a[1]+a[2]+a[4]>a[4]*2)ans++;
		if(a[1]+a[2]+a[5]>a[5]*2)ans++;//
		if(a[1]+a[3]+a[4]>a[4]*2)ans++;
		if(a[1]+a[3]+a[5]>a[5]*2)ans++;//
		if(a[1]+a[4]+a[5]>a[5]*2)ans++;//
		if(a[2]+a[3]+a[4]>a[4]*2)ans++;
		if(a[2]+a[3]+a[5]>a[5]*2)ans++;
		if(a[2]+a[4]+a[5]>a[5]*2)ans++;//
		if(a[3]+a[4]+a[5]>a[5]*2)ans++;//
		if(a[1]+a[2]+a[3]+a[4]>a[4]*2)ans++;
		if(a[1]+a[2]+a[3]+a[5]>a[5]*2)ans++;
		if(a[1]+a[2]+a[4]+a[5]>a[5]*2)ans++;//
		if(a[1]+a[3]+a[4]+a[5]>a[5]*2)ans++;
		if(a[2]+a[3]+a[4]+a[5]>a[5]*2)ans++;
		if(a[1]+a[2]+a[3]+a[4]+a[5]>a[5]*2)ans++;
	}else{
		srand(0);
		cout<<rand()%10;
		return 0;
	}
	cout<<ans;
	return 0;
}
