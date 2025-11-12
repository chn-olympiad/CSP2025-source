#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,k,ans;
int a[MAXN];
struct node{
	int b;
	int e;
}s[MAXN];
int len;
bool cmp(node x,node y){
	if(x.e!=y.e){
		return x.e<y.e;
	}
	return x.b>y.b;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int cnt=0;
			for(int k=i;k<=j;k++){
				cnt=cnt^a[k];
			}
			if(cnt==k){
				len++;
				s[len].b=i;
				s[len].e=j;
			}
		}
	}
	sort(s+1,s+len+1,cmp);
	int w=0;
	for(int i=1;i<=len;i++){
//		cout<<s[i].b<<' '<<s[i].e<<'\n';
		if(s[i].b>w){
			w=s[i].e;
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
