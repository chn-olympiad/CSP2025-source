#include<bits/stdc++.h>
using namespace std;
int MAXN=2e5+5;
struct node{
	string x,y;
}a[200005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) {
			cout<<0<<endl;
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(t1.find(a[i].x)!=-1){
				int l=a[i].x.size();
				int x=t1.find(a[i].x);
				string s=t1;
				for(int j=0;j<l;j++){
					s[j+x]=a[i].y[j];
				}
				if(s==t2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
