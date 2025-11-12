#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int n,q;
string a[N],b[N],c,d;
int ans;
void compare(int i,int j){
	int ji=0;
	while(ji<a[i].size()){
		if(a[i][ji]!=c[j+ji]){
			return;
		}
		ji++;
	}
	ji=0;
	while(ji<c.size()){
		if(j<=ji&&ji-j<a[i].size()){
			if(b[i][ji-j]!=d[ji]){
				return;
			}
		}else{
			if(c[ji]!=d[ji]){
				return;
			}
		}
		ji++;
	}
	ans++;
	return;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	if(n>=1e4){
		for(int i=1;i<=q;i++){
			cout<<0<<'\n';
		}
	} 
	while(q--){
		cin>>c>>d;
		ans=0;
		for(int i=1;i<=n;i++){
			if(c.size()<a[i].size())continue;
			for(int j=0;j<=c.size()-a[i].size();j++){
				if(c[j]==a[i][0]){
					compare(i,j);
				}
			}
		}
		cout<<ans<<'\n';
	}
} 
