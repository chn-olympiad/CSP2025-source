#include<bits/stdc++.h>
using namespace std;
int a[6005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=3){
		if(a[3]*2<a[1]+a[2]+a[3])
		cout<<1;
		else cout<<0;
		return 0;
	}
	int j=3,ans=0,cnt=0;
	/*while(j<=n){
		for(int i=1;i<=j;i++){
			ans+=a[i];
		}
		for(i=j;i<=n;i++){
			if(a[i]*2>ans) break;
			cnt++;
		}
	}*/
	return 0;
}