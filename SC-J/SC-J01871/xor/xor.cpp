#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10,M=1e7+10;
int n,k;
int a[N];
struct node{
	int l,r;
}s[M];
int cnt,ans,bk;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<0 || a[i]>1){
			f=0;
		}
	} 
	if(f){
		if(k==1){
			for(int i=1;i<=n;i++){
				ans+=a[i];
			}
			cout<<ans;
		}else{
			for(int i=1;i<=n;i++){
				ans+=!a[i];
			}
			for(int i=1;i<=n;i++){
				if(a[i] && a[i+1]){
					ans++;
					i++;
				}
			}
			cout<<ans;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		int sum=0;
		for(int j=i;j<=n;j++){
			sum^=a[j];
			if(sum==k){
				s[++cnt].l=i;
				s[cnt].r=j;
			}
		} 
	}
	s[0].l=0;
	s[0].r=0;
	for(int i=1;i<=cnt;i++){
		if(s[i].l>s[bk].r){
			bk=i;
			ans++;
		}else{
			if(s[i].r<=s[bk].r){
				bk=i;
			}
		}
	}
	cout<<ans;
	return 0;
}

//QwQ 65pts