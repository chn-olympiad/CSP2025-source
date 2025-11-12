#include<bits/stdc++.h>
using namespace std;
int x(int a,int b){
	int c[25];
	memset(c,0,sizeof(c));
	int cnt=0;
	while(a>0||b>0){
		if(a%2==b%2){
			cnt++;
		}
		if(a%2!=b%2){
			c[++cnt]=1;
		}
		a=a/2;
		b=b/2;
	}
	int ans=0;
	for(int i=cnt;i>=1;i--){
		ans=ans*2+c[i];
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[500005],p[500005];
	int r[500005];
	memset(a,0,sizeof(a));
	memset(p,0,sizeof(p));
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]=x(p[i-1],a[i]);
	}
	for(int i=1;i<=n;i++){
		int f=x(p[i-1],k);
		for(int j=i;j<=n;j++){
			if(p[j]==f){
				r[i]=j;
				break;
			}
		}
	}
	int maxr=0,ans=0;
	for(int i=1;i<=n;i++){
		if(r[i]==0){
			continue;
		}
		if(i>maxr){
			ans++;
			maxr=r[i];
			continue;
		}
		if(i<=maxr&&r[i]<=maxr){
			maxr=r[i];
			continue;
		}
	}
	cout<<ans;
	return 0;
}
