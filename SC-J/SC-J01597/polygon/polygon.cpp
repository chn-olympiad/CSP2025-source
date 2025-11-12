#include<bits/stdc++.h>
using namespace std;
int n,mx=-1,sum=0,p=1,num=1;
long long ans=0;
int a[5005];
void dfs(int x,int y,int su,int mxx){
	if(x>n){
		if(y>=3&&su>2*mxx){
			ans++;
		}
		return;
	}
	else{
	    dfs(x+1,y+1,su+a[x],max(mxx,a[x]));
		dfs(x+1,y,su,mxx);
		return;
	}
}
long long count1(int x,int y){
	for(int i=y+1;i<=x;i++){
		num=(num%998244353*i%998244353)%998244353;
	}
	for(int i=2;i<=x-y;i++){
		num/=i;
	}
	return num;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			p=0;
		}
		sum+=a[i];
		mx=max(mx,a[i]);
	}
	if(n==3){
		if(sum>2*mx){
			cout<<1;
		}
		else{
			cout<<0;
		}
		return 0;
	}
	if(n<=10){
		dfs(1,0,0,-1);
		cout<<ans;
		return 0;
	}
	if(p==1){
		for(int i=3;i<=n;i++){
			ans=(ans%998244353+count1(n,i)%998244353)%998244353;
			num=1;
		}
		cout<<ans;
		return 0;
	}
	cout<<0;
	return 0;
}