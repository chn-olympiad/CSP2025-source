#include <bits/stdc++.h>
using namespace std;
int n,q,zi[200005];
string s1[200005],s2[200005];
void solve1(){
	while(q--){
		string t1,t2;
		int ans=0;
		cin>>t1>>t2;
		int sz=t1.size();
		t1=" "+t1;
		for(int i=1;i<=sz;i++){
			for(int j=1;j<=n;j++){
				if(i+zi[j]-1>sz) continue;
				string x=i>1?t1.substr(1,i-1):"",y=t1.substr(i,zi[j]),z=(i<=sz)?(t1.substr(i+zi[j],sz-(i+zi[j])+1)):"";
//				cout<<zi[j]<<" x= "<<x<<" y= "<<y<<" z= "<<z<<' '<<s1[j]<<'\n';
				if(y==s1[j]){
//					cout<<"!!!\n\n";
					if(x+s2[j]+z==t2) ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		s1[i]=s1[i],s2[i]=s2[i];
		zi[i]=s1[i].size();
	}
	if(n<=100&&q<=100) solve1();
	return 0;
}
