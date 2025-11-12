#include <bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
struct L{
	string a,b;
};
int n,q;
L a[MAXN];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
	}
	if(n<=1e3){
		while(q--){
			string ks,mb;
			cin>>ks>>mb;
			int sum=0;
			for(int i=1;i<=n;i++){
				int len=ks.size(),le=a[i].a.size();
				for(int j=0;j+le-1<len;j++){
					if(ks.substr(j,le)==a[i].b){
						if(ks.substr(0,j)+a[i].b+ks.substr(j+le-1,len-j-le-1)==mb){
							sum++;break;
						}
					}
				}
			}
			cout<<sum<<'\n';
		}
		return 0;
	}
	for(int i=1;i<=q;i++){
		cout<<0<<'\n';
	}
	return 0;
}
