#include <bits/stdc++.h>
using namespace std;
int n,q;
string a[500005];
string b[500005];
bool pd(string x,int l,string y){
	int len=y.size();
	for(int i=0;i<len;i++){
		if(x[l+i]!=y[i]){
			return 0;
		}
	}
	return 1;
}
void solve(){
	string x,y;
	cin>>x>>y;
	if(x.size()!=y.size()){
		cout<<0<<endl;
		return;
	}
	int len=x.size();
	int ans=0;
	for(int i=1;i<=n;i++){
		int lenn=a[i].size();
		for(int j=0;j+lenn-1<len;j++){
//			cout<<x<<' '<<j<<' '<<a[i]<<' '<<pd(x,j,a[i])<<' '<<pd(y,j,b[i])<<endl;
			if(pd(x,j,a[i])==1 && pd(y,j,b[i])==1){
				int Flag=0;
//				cout<<j<<' '<<j+lenn-1<<endl;
				for(int k=0;k<len;k++){
					if(k<j || k>j+lenn-1){
						if(x[k]!=y[k]){
							Flag=1;
							break;
						}
					}
					
				}
				if(Flag==0){
					ans++;
				}
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	while(q--) solve();
	
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
