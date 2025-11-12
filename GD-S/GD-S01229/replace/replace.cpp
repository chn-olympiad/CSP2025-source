#include<bits/stdc++.h>
using namespace std;
int n,m,f,k,ans;
bool flag;
string st1[100005],st2[100005],a,b;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>st1[i]>>st2[i];
	while(m--) {
		cin>>a>>b;
		for(int i=1;i<=n;i++){
			k=a.find(st1[i]);
			f=b.find(st2[i]);
			if(k==f&&k<a.size()&&f<b.size()&&k>=0&&f>=0) {
				flag=true;
				for(int j=0;j<a.size();j++) {
					if(j>=k&&j<k+st1[i].size()) continue;
					if(a[j]!=b[j]) {
						flag=false;
						break;
					}
				}
				if(flag) ans++;
			}
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}
