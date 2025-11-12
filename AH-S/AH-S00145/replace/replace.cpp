#include <bits/stdc++.h>
using namespace std;

string x[200005],y[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
	while(q--){
		string p1,p2;
		cin>>p1>>p2;
		int len=p1.length();
		int ans=0;
		for(int i=1;i<=n;i++){
			int rp=x[i].length();
			for(int j=0;j<len-rp+1;j++){
				if (x[i]==p1.substr(j,rp)){
					string v=p1.substr(0,j)+y[i]+p1.substr(j+rp,len-j-rp);
					if (v==p2) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
