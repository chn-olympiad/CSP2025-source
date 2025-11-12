#include<bits/stdc++.h>
using namespace std;
const int N=5e6+5;
int n,q,nxt[N],f[N];
string s1[N],s2[N],l1,l2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1[i]>>s2[i];
		s1[i]=" "+s1[i];
	}
	for(int qq=1;qq<=q;qq++){
		int ans=0;
		cin>>l1>>l2;
		l1=" "+l1;
		int tot=l1.size();
		for(int k=1;k<=n;k++){
			memset(nxt,0,sizeof nxt);
			int pos=0;
			int len=s1[k].size();
			string a=s1[k];
			for(int i=2,j=0;i<len;i++){
				while(j&&a[i]!=a[j+1]) j=nxt[j];
				if(a[i]==a[j+1]) j++;
				nxt[i]=j;
			}
			for(int i=1,j=0;i<tot;i++){
				while(j&&(j==len-1||a[j+1]!=l1[i])) j=nxt[j];
				if(a[j+1]==l1[i]) j++;
				if(j==len-1) f[++pos]=i-len+2;
			}
			for(int i=1;i<=pos;i++){
				string l1h;
				string l11;
				l11=l1.substr(1,f[pos]-1);
				l1h=l1.substr(f[pos]+len-1,tot-f[pos]-len+1);
				if(l11+s2[k]+l1h==l2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

