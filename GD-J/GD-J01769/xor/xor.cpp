#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7;
int a[N],vis[N]={0};
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,k;
	bool f=true,fb=true;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) f=false;
		if(a[i]!=1 && a[i]!=0) fb=false;
	}
	if(f && k==0 && n==1) cout<<0;
	else if(f && k==0 && n==2) cout<<1;
	else if(f && k==0) cout<<n/2;
	else if(fb && k==0){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt++;
		}
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1] && a[i]==1){
				cnt++;
				i++;
			}
		}
		cout<<cnt;
	}
	else if(fb && k==1){
		int cnt1=0;	
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt1++;
		}
		cout<<cnt1;
	}
	else{
		int cnt2=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k){
				vis[i]=-1;
				cnt2++;
			}
			else{
				int x=a[i];
				for(int j=i+1;j<=n;j++){
					if(x==k){
						cnt2++;
						break;
					}
					if(vis[j]==0) x=a[j]^x;
					else continue;
				}
			}
		}
		cout<<cnt2;	
	}
	return 0;
} 
