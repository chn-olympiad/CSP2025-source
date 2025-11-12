#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
int b[N];
int n;
int k;
int ans;
int cnt;

int dfs2(int r,int l,int sum){
	if(sum==k) return r;
	if(r>l) return 2147483647;
	return min(dfs2(r+1,l,sum),dfs2(r+1,l,sum^b[r]));
}

int chep(int r,int l){
	while(r<=l) {
		int p=dfs2(r,l,0);
		ans++;
		if(p!=2147483647) r=p+1;
	}
}

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	bool flag1=0,flag0=0;
	for(int i=1;i<=n;i++) {
		cin>>b[i];
		if(b[i]!=1) flag1=1;
		if(b[i]!=1&&b[i]!=0) flag0=1;
	}
	if(k==0&&flag1==0){
		cout<<n/2;
		return 0;
	}
	if(flag0==0){
		if(k==0) {
			for(int i=1;i<=n;i++){
				if(b[i]==0) ans++;
				if(b[i]==1&&b[i+1]==1) ans++,b[i+1]=-1;
			}cout<<ans;
			return 0;
		}else {
			for(int i=1;i<=n;i++){
			if(b[i]==1) ans++;
			} 
			cout<<ans;
			return 0;
		}return 0;//多余了，但不删 QwQ
	}
	int last=1;
	for(int i=1;i<=n;i++){
		if(b[i]==k) {
			if(b[i-1]!=k) chep(last,i-1);
			ans++;
			last=i+1;
		}
	}if(b[n]!=k) ans+=chep(last,n);
	cout<<ans;
	return 0;
}
/*
5
2 2 3 8 10
*/
