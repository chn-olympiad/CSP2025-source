#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N];
int sum[N];
int n,k;
int check[(1<<20)+10];
int vis[(1<<20)+10];
int qu[N];
int ans[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	memset(check,0,sizeof check);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(a[i]==k){
			qu[i]=i;
		}
		else if(sum[i]==k)qu[i]=1;
		else if(check[sum[i]^k]&&!vis[sum[i]^k])
		{
			qu[i]=check[sum[i]^k]+1;
			vis[sum[i]^k]=1;
		}
		check[sum[i]]=i;
		vis[sum[i]]=0;
	}
	int Maxx=0;
	for(int i=1;i<=n;i++){
		//cout<<qu[i]<<" ";
		if(qu[i])
		{
			ans[i]=ans[qu[i]-1]+1;
		}
		ans[i]=max(ans[i],ans[i-1]);
		Maxx=max(Maxx,ans[i]);
		//cout<<ans[i]<<endl;
	}
	cout<<Maxx<<endl;
	return 0;
} 
