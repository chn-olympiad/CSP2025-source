#include<bits/stdc++.h>
using namespace std;
int n,k;
int gi[500009];
int qz[500009];
bool zerofl = 0,onefl = 0;
int ta = -1;
long long ls;
void dfs(int l,int r,int ans) { //ans取到的区间数量
	if(r>n||l>n||l>r) {
//		for(int i = 1;i<=lis[0][0];i++){
//			cout<<"now find:"<<lis[i][0]<<" "<<lis[i][1]<<endl;
//		}
//		cout<<ans<<" no more\n";
		ta = max(ta,ans);
		return;
	}
	int num = qz[r]^qz[l-1];
//	cout<<l<<" "<<r<<endl;
	if(num == k) {
//		lis[++lis[0][0]][0] = l;
//		lis[lis[0][0]][1] = r;
//		cout<<" find"<<endl;
		dfs(r+1,r+1,ans+1);

	} else {
		dfs(l,r+1,ans);
		dfs(l+1,r,ans);
	}
}
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i = 1; i<=n; i++) {
		cin>>gi[i];
		if(gi[i]!=0) {
			zerofl = 1;
		}
		if(gi[i]>1) {
			onefl = 1;
		}
		ls+=gi[i];
	}
	if(!zerofl&&k == 0) {//a
		cout<<n;
		return 0;
	}
	if(!onefl) {//b
		if(k == 0) {
			ls = n-ls;
			for(int i = 1; i<=n; i++) {
				if(gi[i] == 1) {
					int tep = 0;
					for(int j = i;; j++) {
						if(gi[j]!=1) {
							break;
						}
						tep++;
					}
					ls+=(tep/2);
					i+=(tep-1);
				}
			}
		}
		cout<<ls;
		return 0;
	}
	qz[1] = gi[1];
	for(int i = 2; i<=n; i++) {
		qz[i] = qz[i-1]^gi[i];
	}
	dfs(1,1,0);
	cout<<ta;
	return 0;
}

