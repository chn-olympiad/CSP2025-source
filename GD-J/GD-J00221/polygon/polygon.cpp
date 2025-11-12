#include<bits/stdc++.h>
using namespace std;
long long ans,n,arr[5010],maxn,sum;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	sort(arr+1,arr+n+1,cmp);
	maxn=arr[1];
	if(n<=3){
		if(arr[1]+arr[2]+arr[3]>maxn*2) cout<<1;
		else cout<<0;
	}
	else {
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					if(arr[i]+arr[j]+arr[k]>2*arr[i]) ans++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
