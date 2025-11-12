#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010];
int x[10000],y[10000];
int p[500010];
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int t=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<n-i;i++){
			int s=i;
			for(int k=i+1;k<=i+j;j++){
				s^=a[k];
			}
			if(s==m){
				x[t]=i;
				y[t]=i+j;
				t++;
			}
		}
	}
	int ans=0;
	for(int i=0;i<t;i++){
		int p1[500010];
		int f=0;
		for(int j=x[i];j<=y[i];j++){
			if(p1[j]==1){
				f=1;
				break;
			}
			p1[j]=1;
		}
		if(f==0){
			ans++;
			for(int j=x[i];j<=y[i];j++){
				p[j]=1;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
