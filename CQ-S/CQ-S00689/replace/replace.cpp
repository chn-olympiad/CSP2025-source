#include<bits/stdc++.h>
using namespace std;
long long n,q,num[5000010],pre[5000010],la[5000010];
string c,d;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string o,p;
		cin>>o>>p;
		for(int j=0;j<o.size();j++){
			if(o[j]=='b'){
				num[i]=j;
				pre[i]=j;
				la[i]=o.size()-pre[i]-1;
				break;
			}
		}
		for(int j=0;j<p.size();j++){
			if(p[j]=='b') {
				num[i]-=j;
			}
		}
	}
	for(int i=1;i<=q;i++){
		cin>>c>>d;
		long long p,l,b,h,ans=0;
		for(int j=0;j<=c.size();j++){
			if(c[j]=='b'){
				b=j;
				p=j;
				l=c.size()-p-1;
				break;
			}
		}
		for(int j=0;j<=d.size();j++){
			if(d[j]=='b'){
				h=j;
			}
		}
		for(int j=1;j<=n;j++){
			if(pre[j]<=p&&la[j]<=l&&b-num[j]==h) ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
