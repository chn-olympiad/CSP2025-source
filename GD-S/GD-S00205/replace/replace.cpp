#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,q,ans,len1[N];
string s1[N],s2[N],t1,t2;
inline void mian(){
	cin>>t1>>t2;ans=0;
	int len=t1.length();
	for(int i=1;i<=n;i++){
		if(len1[i]>len)continue;
		string x="",y=t1.substr(0,len1[i]),z=t1.substr(len1[i],len-1);
//		cout<<x<<' '<<y<<' '<<z<<'\n';
		if(y==s1[i]&&x+s2[i]+z==t2)ans++;
		for(int j=0;j<len-len1[i];j++){
			if(y==s1[i]&&x+s2[i]+z==t2){ans++;break;}
			x+=t1[j];y=y.substr(1,len1[i])+t1[j+len1[i]];
			int lenz=z.length();
			z=z.substr(1,lenz-1);
//			cout<<x<<' '<<y<<' '<<z<<' '<<ans<<'\n';
		}
	}cout<<ans<<'\n';
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		len1[i]=s1[i].length();
	}while(q--)mian();
	return 0;
}
