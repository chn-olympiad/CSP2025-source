#include<bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
const int MAXN=5e5+1;
int n,k;
int a[MAXN];
int pre[MAXN];
bool vis[MAXN];
int now;
int ans;
bool f;
//-----------------------------
int cnt;
int fid[MAXN];
pair<int,int> g[MAXN];
int r;
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.y<b.y;
}
void RPplus(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n-i+1;++j){
			now=pre[j+i-1]xor pre[j-1];
//			if(vis[j]||vis[j+i-1]){
//				vis[j]=true;
//				vis[j+i-1]=true;
//				continue;
//			}
			f=false;
			for(int l=j;l<=j+i-1;++l){
				if(vis[l]){
					f=true;
					break;
				}
			}
			if(f){
				continue;
			} 
			if(now==k){
				++ans;
//				cout<<j<<' '<<j+i-1<<'\n';
				for(int l=j;l<=j+i-1;++l){
					vis[l]=true;
				}
			}
		}
	}
	cout<<ans;
}

void RPplusplus(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n-i+1;++j){
			now=pre[j+i-1]xor pre[j-1];
//			if(vis[j]||vis[j+i-1]){
//				vis[j]=true;
//				vis[j+i-1]=true;
//				continue;
//			}
			if(now==k){
//				++ans;
//				cout<<j<<' '<<j+i-1<<'\n';
//				for(int l=j;l<=j+i-1;++l){
//					vis[l]=true;
//				}
				++r;
				pair<int,int> p;
				p.x=j,p.y=j+i-1;
				g[r]=p;
			}
		}
	}
//	cout<<r<<'\n';
	sort(g+1,g+r+1,cmp);
	for(int i=1;i<=r;++i){
//		cout<<g[i].x<<' '<<g[i].y<<'\n';
	} 
	for(int i=1;i<=r;++i){
		if(!fid[i]){
//			cout<<g[i].x<<' '<<g[i].y<<'\n';
			++ans;
			now=g[i].y;
			for(int j=i;j<=r;++j){
				if(now>=g[j].x&&now<=g[j].y){
					fid[j]=true;
				}else{
					break;
				}
			}
		}
	}
	cout<<ans;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		pre[i]=pre[i-1]xor a[i];
//		cout<<pre[i]<<' ';
	}
//	cout<<'\n';
	RPplusplus();
	return 0;
}
//CCF保佑,弄不好真成信竞绝唱了 