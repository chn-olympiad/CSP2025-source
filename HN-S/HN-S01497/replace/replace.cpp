#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;
struct str{
	string x,y;
} a[200005];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	  cin>>a[i].x>>a[i].y;
	ll ans=0;
	for(int i=1;i<=q;i++){
		string x,y;
		cin>>x>>y;
		for(int j=1;j<=n;j++){
			int fx=x.find(a[j].x),fy=y.find(a[j].y);
			if(fx==fy&&fx>=0&&fx<x.size()){
				int ff=1;
				for(int k=fx+a[j].x.size();k<x.size();k++){
					if(x[k]!=y[k]){
						ff=0;
						break;
					}
				}
//				cout<<i<<' '<<j<<'\n';
				if(ff==1)
				  ans++;
			}
			  
		}
		cout<<ans<<'\n';
		ans=0;
	}
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
