#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+200;
int n,k,a[N],s[N],vis[N],tot=0;
int dis[N];
bool cmp(int x,int y){
	return x>y;
}
bool fun(int x){
	if(x==2||x==3){
		return true;
	}else if(x==1){
		return false;
	}
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0){
			return false;
		}
	}
	return true;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=100;i++){
		if(fun(i)==true){
			vis[++tot]=i;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i];
	}
//	for(int i=1;i<=n;i++){
//		sum[i]=a[i]^a[i-1];
//	}
//	for(int i=1;i<=n;i++){
//		cout<<sum[i]<<" ";
//	}
	sort(a+1,a+1+n,cmp);
	if(a[n]==1&&k==1){
		cout<<"0";
		return 0;
	}
	if(a[1]==1&&a[n]==1&&k==0){
		for(int i=1;i<=tot;i++){
			if(n%vis[i]==0){
				cout<<n/vis[i];
				return 0;
			}
		}
	}else{
		int ans=0;
		tot=0;
		for(int i=1;i<=n;i++){
			if(s[i]==k){
				dis[++tot]=i;
				ans++;
			}
		}
		if(k==0){
			for(int i=1;i<=n;i++){
				if(s[i]==1&&s[i+1]==1){
					ans++,i++;
				}
			}
		}
		cout<<ans;
	}
	return 0;
}
/*
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

*/
