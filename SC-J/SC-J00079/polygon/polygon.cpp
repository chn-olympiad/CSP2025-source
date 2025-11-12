#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005],b[100005],ans=0;
int n;
bool used[1000005];
void go(int bushu,int zong,int wei){
	if(bushu==n+1) return;
	for(int i=wei+1;i<=n;i++){
		if(!used[i]){
			used[i]=1;
			if(bushu>=3&&zong+a[i]>a[i]*2) ans=(ans+1)%998244353;
			go(bushu+1,zong+a[i],i);
			used[i]=0;
		}
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int flag=0;
	cin>>n;
	for(int i=1;i<=n;i++){cin>>a[i];if(a[i]!=1) flag=1;}
	if(flag){
		sort(a+1,a+n+1);
		go(1,0,0);
		cout<<ans;	
	}else{
		int ans=0;
		for(int i=3;i<=n;i++){
			int sum=1,op=1;
			for(int j=n;j>=n-i+1;j--){
				sum=sum*j/(n-j+1)%998244353;
			}
			ans=(ans+sum)%998244353;
		}
		cout<<ans;
	} 
	return 0;
}
//while(1) rp++;