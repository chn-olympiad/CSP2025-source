#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans=0,a[5005],b[5005];
bool all_1=true;
struct node{
	int num=0,sum=0,maxx=0;
	bool f=false;
};
vector<node>e[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	memset(b,0,sizeof(b));
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]&&i!=1){
			all_1=false;
		}
	}
	if(all_1){
		if(n<=2){
			cout<<0;
		}else{
			for(int i=3;i<=n;i++){
				int x=1,y=1;
				for(int j=1;j<=i;j++){
					y*=j;
					x*=(n-j+1);
				}
				ans+=x/y;
			}
			cout<<ans;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(i-2>=0){
			e[i-2].clear();
		}
		node m;
		m.num=1;
		m.sum=m.maxx=a[i];
		m.f=false;
		e[i].push_back(m);
		for(int j=0;j<(int)e[i-1].size();j++){
			int x=e[i-1][j].num,y=e[i-1][j].sum,z=e[i-1][j].maxx;
			bool f=e[i-1][j].f;
			m.num=x;
			m.sum=y;
			m.maxx=z;
			m.f=f;
			e[i].push_back(m);
			x++;
			y+=a[i];
			z=max(z,a[i]);
			f=(y>2*z&&x>2);
			m.num=x;
			m.sum=y;
			m.maxx=z;
			m.f=f;
			e[i].push_back(m);
		}
	}
	for(int i=0;i<(int)e[n].size();i++){
		if(e[n][i].f){
			ans++;
			ans%=998244353;
		}
	}
	cout<<ans%998244353;
	return 0;
}