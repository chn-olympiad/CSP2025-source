#include<bits/stdc++.h>
using namespace std;
string t[200010][2];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>t[i][0]>>t[i][1];
	while(q--){
		string x,y;
		cin>>x>>y;
		if(x.size()!=y.size()){
			cout<<"0\n";
			return 0;
		}
		int ln=x.size();
		x=' '+x,y=' '+y;
		int l,r;
		for(int i=1;i<=ln;i++){
			if(x[i]!=y[i]){
				l=i;
				break;
			}
		}
		for(int i=ln;i>=1;i--){
			if(x[i]!=y[i]){
				r=i;
				break;
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			int v=t[i][0].size();
			int p=x.find(t[i][0],max(0,l-v+1));
			if(p!=-1&&p<=r){
				string b=x;
				b.erase(p,v);
				b.insert(p,t[i][1]);
				if(b==y)ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
