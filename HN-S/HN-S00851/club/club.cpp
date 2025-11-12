#include<bits/stdc++.h>
using namespace std;
int t,n,ans;
int a[4][100100];
struct clb{
	int id,w;
};
bool f[100100];
vector<int> g;
bool cmp(int a,int b){
	return a>b;
}
void comp(int a,int b,int c,int d){
	if(a+b+c==n)ans=max(ans,d);
}
void fid(int x,int y,int z,int aa){
	//cout<<x<<' '<<y<<' '<<z<<' '<<aa<<endl;
	if(x+y+z==n+1){
		ans=max(aa,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			if(x+1<=n/2){
				comp(x+1,y,z,aa+a[1][i]);
				fid(x+1,y,z,aa+a[1][i]);
			}
			if(y+1<=n/2){
				comp(x,y+1,z,aa+a[2][i]);
				fid(x,y+1,z,aa+a[2][i]);
			}
			if(z+1<=n/2){
				comp(x,y,z+1,aa+a[3][i]); 
				fid(x,y,z+1,aa+a[3][i]); 
			}
			f[i]=0;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;ans=0;
		for(int i=1;i<=3;i++){
			f[i]=0;
			g.clear();
		}
		bool f=1;
		for(int i=1;i<=n;i++){
			int ma=0,p,s=0;
			for(int j=1;j<=3;j++){
				cin>>a[j][i];
				}
				if(a[2][i]||a[3][i])f=0;
				g.push_back(a[1][i]);
			}
		if(f){
			sort(g.begin(),g.end(),cmp);
			int ans=0;
			for(int i=0;i<n/2;i++){
				ans+=g[i];
			}
			cout<<ans<<endl;
		}
		fid(0,0,0,0);
		cout<<ans<<endl;
	}	
	return 0;
}
