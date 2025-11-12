#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int l[50020];
int pre[50020];
int p[500020];
int f[510][510];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>l[i];
	sort(l+1,l+n+1);
	pre[0]=0;
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+l[i];
		p[i]=l[i]-l[i-1];
	}
	if(pre[2]>l[3]) f[3][3]=1;
	for(int i=4;i<=n;i++){
		for(int j=3;j<=i;j++){
			if(f[i-1][j-1]){
				if(l[i-1]>=l[i]-pre[i-2]){
					f[i][j]++;
				}
			}else if(l[i-1]*2-(pre[i-1]-pre[i-j-1])>l[i]){
				f[i][j]+=pre[i-1]-pre[i-j-1];
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans+=f[i][j];
		}
	}
	cout<<ans;
}
