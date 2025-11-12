#include<bits/stdc++.h>
using namespace std;
#define int long long
const int p=13131;
map<int,int>mp;
string s1,s2;
int ha[2005],n,q,hp[2005];
signed main()
{
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		int ha1=0,ha2=0;
		for(int j=0;j<s1.size();j++){
			ha1=ha1*p+s1[j];
		}
		for(int j=0;j<s2.size();j++){
			ha2=ha2*p+s2[j];
		}
		mp[ha1]=ha2;
	}
	hp[0]=1;
	for(int i=1;i<=2000;i++) hp[i]=hp[i-1]*p;
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		s1=' '+s1;
		int nha=0,ans=0;
		for(int j=1;j<s1.size();j++){
			ha[j]=ha[j-1]*p+s1[j];
		}
		for(int j=0;j<s2.size();j++){
			nha=nha*p+s2[j];
		}
		for(int j=1;j<s1.size();j++){
			for(int k=j;k<s1.size();k++){
				int qwq=ha[k]-ha[j-1]*hp[s1.size()-j-1];
				int qaq=mp[qwq];
				if((ha[s1.size()-1]-qwq*hp[s1.size()-k-1]+qaq*hp[s1.size()-k-1])==nha) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}/*
2 1
iakioi ioiaki
akio oiak
iakioi ioiaki
*/
