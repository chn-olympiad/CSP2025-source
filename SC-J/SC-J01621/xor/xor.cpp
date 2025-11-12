#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;
//struct st{
//	int l;
//	int r;
//}p[1000007];
int a[500007];
int b[500007];
int ans;
int o;
int num0,num1;
int cnt;
//bool cmp(st x,st y){
//	return x.r-x.l+1<y.r-y.l+1;
//}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=0&&a[i]!=1)	o=1;
		if(a[i]==0)	num0++;
		if(a[i]==1)	num1++;
		b[i]=b[i-1]^a[i];
	}
	if(!o){
		if(k==0)	cout<<num0;
		if(k==1)	cout<<num1;
		else	cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((b[i]^b[j-1])==k){
//				p[++cnt].l=j;
//				p[++cnt].r=i;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
