#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,q,ans;
struct node{
	string a,b;
	int numa,numb;
}a[200005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
		for(int j=0;j<a[i].a.size();j++){
			if(a[i].a[j]=='b'){
				a[i].numa=i;
				break;
			}
		}
		for(int j=0;j<a[i].b.size();j++){
			if(a[i].b[j]=='b'){
				a[i].numb=i;
				break;
			}
		}
	}
	while(q--){
		string x;
		cin>>x;
		int num=0;
		ans=0;
		for(int i=0;i<x.size();i++){
			if(x[i]=='b'){
				num=i;
				break;
			}
		}
		for(int i=1;i<=n;i++){
			if(a[i].a.size()==a[i].b.size()){
				if(a[i].numa<=num && x.size()-num-1>=a[i].a.size()-a[i].numa-1){
					if(a[i].numb<=num && x.size()-num-1>=a[i].b.size()-a[i].numb-1){
						ans++;
					}
				}
			} 
		}
		cout<<ans<<"\n";
	}
	return 0;
}
