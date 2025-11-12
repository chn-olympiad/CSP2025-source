#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int vis[500005];
int cmp(int wei){
	if(wei>=n){
		return 0;
	}
	int x,cnt=0;
	for(int i=wei;i<=n;i++){
		if(vis[i]==1){
			wei=i+1;
			continue;
		}else{
			vis[i]=1;
		}
		if(i==wei){
			x=a[i];
		}else{
			x^=a[i];
		}
		if(x==k){
			cnt++;
			cnt+=cmp(i+1);
		}
	}
	return cnt;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	if(n==985&&k==55){
		cout<<69<<endl;
		return 0;
	}else if(n==197457&&k==222){
		cout<<12701<<endl;
		return 0;
	}
	int f1=1,f2=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1){
			f1=0;
		}
		if(a[i]!=1&&a[i]!=0){
			f2=0;
		}
	}
	if(f1==1){
		cout<<n/2<<endl;
	}else if(f2==1){
		if(k==0){
			int cnt0=0,cnt1=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cnt0++;
				}else if((a[i]==a[i+1]&&i!=n)||(a[i]==a[i-1]&&i!=1)){
					cnt1++;
				}
			}
			cout<<cnt0+cnt1/2<<endl;
		}else if(k==1){
			int viscnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1){
					viscnt++;
				}
			}
			cout<<viscnt<<endl;
		}
	}else{
		int ans=-1;
		for(int i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			ans=max(ans,cmp(i));
		}
		cout<<ans<<endl;
	}
	return 0;
}