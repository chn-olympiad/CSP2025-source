#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int k=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) {k=(k<<1)+(k<<3)+ch-48;ch=getchar();}
	return k*f;
}
int n,q;
const int N=2e5+7;
string s1[N],s2[N],u,v;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>s1[i]>>s2[i];
	while(q--){
		int ans=0;
		cin>>u>>v;
		for(int i=1;i<=n;i++){
			for(int j=0;j+s1[i].size()-1<u.size();j++){
				string w=u.substr(0,j);
				string w2=u.substr(j,s1[i].size());
				string w3=u.substr(j+s1[i].size(),u.size()-j-s1[i].size()+1);
				if(w2==s1[i] && w+s2[i]+w3==v) ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
