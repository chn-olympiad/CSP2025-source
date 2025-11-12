#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,ans,p=0;
bool f=true;
int a[5010],c[5010][5010][2];
struct node{
	int sum,edge;
}b[5010];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1) f=0;
		else p++;
	}
	if(n==3){
		sort(a+1,a+4);
		if(a[1]+a[2]>a[3]) cout<<"1";
		else cout<<"0";
		return 0;
	}
	for(int i=1;i<=5000;i++) b[i].sum=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5000-a[i];j++){
			if(b[j].sum){
				b[j+a[i]].sum++;
				for(int k=1;k<=b[j+a[i]].sum;k++){
					c[j+a[i]][k][0]=max(a[i],c[j][k][0]);
					c[j+a[i]][k][1]++;
				}
			}
		}
		b[a[i]].sum++;
		c[a[i]][b[a[i]].sum][0]=a[i];
		c[a[i]][b[a[i]].sum][1]=1;
	}
	for(int i=1;i<=5010;i++){
		for(int j=1;j<=b[i].sum;j++){
			if(c[i][j][1]>=3&&c[i][j][0]*2<i){
				ans++;
				ans=(ans%mod+mod)%mod;
			}
		}
	}
	cout<<ans;
	return 0;
}

