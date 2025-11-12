#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	do{x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}while(ch>='0'&&ch<='9');
	return f?-x:x;
}
int n,q,ans;
string s[200001][2],a,b;
signed main(){
	freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
	n=rd(),q=rd();
	for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
	while(q--){
		cin>>a>>b,ans=0;
		for(int i=1;i<=n;i++){
			for(int j=0,k=0;j+s[i][0].size()<=a.size();j++){
				string t=a.substr(j,s[i][0].size());
				if(t!=s[i][0])continue;
				t=a.substr(k,j-k)+s[i][1]+a.substr(j+s[i][0].size(),a.size()-s[i][0].size()-j);
				if(t==b)ans++;k=j;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
