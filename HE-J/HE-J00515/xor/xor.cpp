#include <bits/stdc++.h>
using namespace std;
const int maxn=500005;

int n,k;
int a[maxn];
int pre[maxn];
int ans;
map<int,bool> tong;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		pre[i]=pre[i-1]^a[i];
	}
	for(int i=0;i<=n;++i){
//		cout<<pre[i]<<':';
//		for(map<int,bool>::iterator b=tong.begin();b!=tong.end();++b){
//			if((*b).second)	cout<<(*b).first<<' ';
//		}cout<<'\n';
		if(tong[pre[i]^k]){
			++ans;
			tong.clear();
		}
		tong[pre[i]]=true;
	}
	cout<<ans;
	return 0;
	
}
