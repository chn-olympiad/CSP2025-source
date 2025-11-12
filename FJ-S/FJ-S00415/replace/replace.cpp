#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll read(){
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
const ll N=2e5+10;
ll n,_,len,l[N],ans;
string s[N][2],x,y;
bool sm[N][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	_=read();
	for (int i=1;i<=n;i++) {
		cin>>s[i][0]>>s[i][1];
		l[i]=s[i][0].length();
	}
	while(_--){
		ans=0;
		cin>>x>>y;
		len=x.length();
		for (int i=0;i<len;i++) sm[i][0]=sm[i][1]=0;
		for (int i=0;i<len;i++){
			if(x[i]==y[i]) sm[i][0]=1;
			else break;
		}
		for (int i=len-1;i>=0;i--){
			if(x[i]==y[i]) sm[i][1]=1;
			else break;
		}
		for (int i=1;i<=n;i++){
			for (int j=0;j<=len-l[i];j++){
				if((int)x.find(s[i][0],j)==j){
					if(j&&(!sm[j-1][0])) continue;
					if(j+l[i]<len&&(!sm[j+l[i]][1])) continue;
					bool flag=true;
					for (int k=0;k<l[i];k++){
						if(y[j+k]!=s[i][1][k]) {
							flag=false;
							break;
						}
					}
					if(flag) ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
