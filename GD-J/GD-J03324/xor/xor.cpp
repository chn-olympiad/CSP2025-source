#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[500009];
bool vis[500009];
void solve1(){
	int cnt = 0;
	for(int l = 1;l<=n;++l){
		for(int r = l;r<=n;++r){
			bool flag = 1;
			for(int i = l;i<=r;++i){
				if(vis[i]) flag = 0;
				break;
			}
			if(!flag) continue;
			int xors = 0;
			for(int i = l;i<=r;++i){
				xors^=a[i];
			}
			if(xors == k){
				cnt++;
				for(int i = l;i<=r;++i){
					vis[i] = 1;	
				}
			}
		}
	}
	cout<<cnt;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1;i<=n;++i){
		cin>>a[i];
	}
	if(n<=100){
		solve1();
	}else cout<<0;
	fclose(stdin);
	fclose(stdout);
}
