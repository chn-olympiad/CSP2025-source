#include<bits/stdc++.h>
#define int long long 
#define mod 998244353
using namespace std;
const int N = 5005;
int a[N],n;
int maxn=-1e9;
int calc(int a,int b){
	int res = 1;
	for(int i=1;i<=b;i++){
		res=res*a/i%mod;
		a--;
	}
	return res;
}
int dfs(int maxx,int ys,int s,int st,int sa){
	if(st>n){
		return 0;
	}
	
	int res=0;
	if(n-st>sa-ys)res+=dfs(maxx,ys,s,st+1,sa);
	if(ys+1==sa){
		if(maxx>=s+a[st]){
			return res;
		}else return res+1;
	}
	return res+dfs(maxx,ys+1,s+a[st],st+1,sa);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		maxn=max(a[i],maxn);
	}
	sort(a+1,a+n+1,greater<int>());
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		int ans=0;
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++){
					if(a[i]<a[j]+a[k]){
						++ans;
					} 
				}
		cout<<ans;
		return 0;
	}
	if(n==4){
		int ans=0;
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++){
					if(a[i]<a[j]+a[k]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++){
					if(a[i]<a[j]+a[k]+a[l]){
						++ans;
					} 
				}
		cout<<ans;
		return 0;
	}
	if(n==5){
		int ans=0;
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++){
					if(a[i]<a[j]+a[k]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++){
					if(a[i]<a[j]+a[k]+a[l]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p){
					if(a[i]<a[j]+a[k]+a[l]+a[p]){
						++ans;
					} 
				}
		cout<<ans;
		return 0;
	}
	if(n==6){
		int ans=0;
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++){
					if(a[i]<a[j]+a[k]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++){
					if(a[i]<a[j]+a[k]+a[l]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p){
					if(a[i]<a[j]+a[k]+a[l]+a[p]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p)for(int q=1;q<=n;q++){
					if(a[i]<a[j]+a[k]+a[l]+a[p]+a[q]){
						++ans;
					} 
				}
		cout<<ans;
		return 0;
	}
	if(n==7){
		int ans=0;
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++){
					if(a[i]<a[j]+a[k]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++){
					if(a[i]<a[j]+a[k]+a[l]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p){
					if(a[i]<a[j]+a[k]+a[l]+a[p]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p)for(int q=1;q<=n;q++){
					if(a[i]<a[j]+a[k]+a[l]+a[p]+a[q]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p)for(int q=1;q<=n;q++)for(int w=p+1;w<=n;w++){
					if(a[i]<a[j]+a[k]+a[l]+a[p]+a[q]+a[w]){
						++ans;
					} 
				}
		cout<<ans;
		return 0;
	}
	if(n==8){
		int ans=0;
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++){
					if(a[i]<a[j]+a[k]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++){
					if(a[i]<a[j]+a[k]+a[l]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p){
					if(a[i]<a[j]+a[k]+a[l]+a[p]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p)for(int q=1;q<=n;q++){
					if(a[i]<a[j]+a[k]+a[l]+a[p]+a[q]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p)for(int q=1;q<=n;q++)for(int w=p+1;w<=n;w++){
					if(a[i]<a[j]+a[k]+a[l]+a[p]+a[q]+a[w]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p)for(int q=1;q<=n;q++)for(int w=p+1;w<=n;w++)for(int e=w+1;e<=n;e++){
					if(a[i]<a[j]+a[k]+a[l]+a[p]+a[q]+a[w]+a[e]){
						++ans;
					} 
				}
		cout<<ans;
		return 0;
	}
	if(n==9){
		int ans=0;
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++){
					if(a[i]<a[j]+a[k]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++){
					if(a[i]<a[j]+a[k]+a[l]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p){
					if(a[i]<a[j]+a[k]+a[l]+a[p]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p)for(int q=1;q<=n;q++){
					if(a[i]<a[j]+a[k]+a[l]+a[p]+a[q]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p)for(int q=1;q<=n;q++)for(int w=p+1;w<=n;w++){
					if(a[i]<a[j]+a[k]+a[l]+a[p]+a[q]+a[w]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p)for(int q=1;q<=n;q++)for(int w=p+1;w<=n;w++)for(int e=w+1;e<=n;e++){
					if(a[i]<a[j]+a[k]+a[l]+a[p]+a[q]+a[w]+a[e]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p)for(int q=1;q<=n;q++)for(int w=p+1;w<=n;w++)for(int e=w+1;e<=n;e++)for(int r=e+1;r<=n;r++){
					if(a[i]<a[j]+a[k]+a[l]+a[p]+a[q]+a[w]+a[e]+a[r]){
						++ans;
					} 
				}
		cout<<ans;
		return 0;
	}
	if(n==9){
		int ans=0;
		for(int i=1;i<=n-2;i++)
			for(int j=i+1;j<=n-1;j++)
				for(int k=j+1;k<=n;k++){
					if(a[i]<a[j]+a[k]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++){
					if(a[i]<a[j]+a[k]+a[l]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p){
					if(a[i]<a[j]+a[k]+a[l]+a[p]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p)for(int q=1;q<=n;q++){
					if(a[i]<a[j]+a[k]+a[l]+a[p]+a[q]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p)for(int q=1;q<=n;q++)for(int w=p+1;w<=n;w++){
					if(a[i]<a[j]+a[k]+a[l]+a[p]+a[q]+a[w]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p)for(int q=1;q<=n;q++)for(int w=p+1;w<=n;w++)for(int e=w+1;e<=n;e++){
					if(a[i]<a[j]+a[k]+a[l]+a[p]+a[q]+a[w]+a[e]){
						++ans;
					} 
				}
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				for(int k=j+1;k<=n;k++)for(int l=k+1;l<=n;l++)for(int p=l+1;p<=n;++p)for(int q=1;q<=n;q++)for(int w=p+1;w<=n;w++)for(int e=w+1;e<=n;e++)for(int r=e+1;r<=n;r++)for(int t=r+1;t<=n;++t){
					if(a[i]<a[j]+a[k]+a[l]+a[p]+a[q]+a[w]+a[e]+a[r]+a[t]){
						++ans;
					} 
				}
		cout<<ans;
		return 0;
	}
	if(maxn==1){
		int ans=0;
		for(int i=3;i<=n;i++){
			ans+=calc(n,i);
			ans%=mod;
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n-2;i++)
	{
		for(int j=2;j<=n-i;++j){
			ans+=dfs(a[i],0,0,i+1,j);
		}
	}
	cout<<ans;
}
