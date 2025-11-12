#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x7fffffff;
const int N=2e5+10;
inline int read(){
	int a=0,f=1;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(isdigit(c)){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*f;
}
int n,q,lx,ly,ans;
string a,b,s[N][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	for(int i=1;i<=n;i++){
		cin>>s[i][0];
		cin>>s[i][1];
	}
	while(q--){
		cin>>a>>b;
		lx=a.size();
		ans=0;
		for(int i=1;i<=n;i++){
			ly=s[i][0].size();
			for(int j=0;j<=lx-ly;j++){
				bool flag=1;
				for(int k=0;k<lx;k++){
					if(k<j||k>=j+ly){
						if(a[k]!=b[k]){
							flag=0;
							break;
						}
					}else if(a[k]!=s[i][0][k-j]||b[k]!=s[i][1][k-j]){
						flag=0;
						break;
					}
				}
				if(flag) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

