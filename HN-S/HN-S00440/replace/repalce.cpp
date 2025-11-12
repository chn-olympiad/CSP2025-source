#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,m;
string a[N],b[N],c,d;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	while(m--){
		int f=0;
		cin>>c>>d;
		if(c==d){
			cout<<0<<endl;
			continue;
		}
		for(int i=1;i<=n;i++){
			if(c==a[i]){
				if(d==b[i]){
					f=1;
					break;
				}
			}
			if(c==b[i]){
				if(d==a[i]){
					f=1;
					break;
				}
			}
		}
		if(f==1){
			cout<<1<<endl;
			continue;
		}
		cout<<2<<endl;
	}
	return 0;
}
