#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int len[N],n,q;
pair<string,string> s[N];
int ans;
int main(){
	freopen("replace3.in","r",stdin);
	freopen("replace3.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	for(int i=1;i<=n;i++){ 
		cin>>s[i].first>>s[i].second;
		len[i]=s[i].first.size();
	}
	for(int i=1;i<=q;i++){
		string t1,t2;
		cin>>t1>>t2;
		ans=0;
		for(int j=1;j<=n;j++){
			bool f=0;
			for(int k=0;k+len[j]-1<t1.size();k++){
				int x1=k,x2=0;
				bool flag=1;
				for(int l=1;l<=len[j];l++){
					if(s[j].first[x2]!=t1[x1]){
						flag=0;
						break;
					}
					x1++;
					x2++;
				}
				if(flag){
					f=1;
					string qwq=t1;
					t1.replace(k,len[j],s[j].second);
					if(t1==t2) ans++;
					t1=qwq;
				}
				if(f) break;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
