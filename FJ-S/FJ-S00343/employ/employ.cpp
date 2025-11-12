#include <bits/stdc++.h>
using namespace std;
const int maxn=503;
int n,m,h[maxn],day[maxn];
string s;
int main(void){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=0,k=1;i<n;i++){
		if(s[i]=='0')day[k++]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>h[i];
		if(h[i]==0)continue;
		h[i]=day[h[i]];
		if(h[i]==0)h[i]=n;
	}
	sort(h+1,h+1+n);
	long long ans=1,p,q;
	for(int i=2,l=1,la=0,d=h[1];i<=n;i++){
		if(h[i]==d){
			l++;
		}else{
			if(d==0){
				d=h[i];
				l=1;
				la=i;
				continue;
			}
			p=1,q=1;
			for(int j=1;j<=l;j++){
				p=p*j,q=q*(h[i]-l);
			}
			ans*=(p/q);
			ans%=998244353;
			d=h[i];
			l=1;
			la=i;
		}
	}
	cout<<ans<<endl;
	return 0;
}
