#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005];
int ans=0,maxa=-1;
int b[500005],kk=0;
void dfs(int l,int r){
	if(l>=r){
		maxa=max(ans,maxa);
		ans=0;
		return;
	}
	for(int i=l;i<=r;i++){
		int sum=a[i];
		if(sum==k){
			ans++;
			dfs(i+1,r);
		}
		for(int j=i+1;j<=r;j++){
			sum=sum^a[j];
			if(sum==k){
				ans++;
				dfs(j+1,r);
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	int nn=0,nn1=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1) nn++;
		if(a[i]==0||a[i]==1) nn1++;
	}
	if(nn==n){
		if(k==0){
			cout<<n/2<<"\n";
			return 0;
		}
		else{
			cout<<n<<"\n";
			return 0;
		}
	}
	else if(nn1==n){
		if(k==1){
			for(int i=1;i<=n;i++){
				if(a[i]==1) ans++;
			}
			cout<<ans<<"\n";
			return 0;
		}
		if(k==0){
			
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				else{
					b[++kk]=a[i];
				}
			}
			cout<<kk/2<<"\n";
			return 0;
		}
	}
	dfs(1,n);
	cout<<maxa<<"\n";
	return 0;
}
