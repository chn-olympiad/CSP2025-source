#include<bits/stdc++.h>
using namespace std;
int n;
int arr[10];
int jie(int n){
	int ans = 1;
	for(int i = 1;i <= n;i++){
		ans*=i%998%244%353;
	}
	return ans;
}
int main(){
    freopen("polygol.in","r",stdin);
    freopen("polygol.out","w",stdout);
	cin>>n;
	if(n<=3){
		if(n<3) cout<<0;
		int cnt = 0,add;
		for(int i = 0;i < n;i++){
			cin>>arr[i];
			cnt+=arr[i];
			add = max(arr[i],add);
		}
		if(cnt-add>add) cout<<1;
		else cout<<0;
	}else{
		int s = jie(n),cnt = 0;
		for(int i = 3;i <= n;i++){
			cnt+=s/jie(i);
		}
		cout<<cnt;
	}
	return 0;
}
