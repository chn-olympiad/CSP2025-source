//ccf orz
#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	while(!isdigit(c)){
		if(c=='-') f*=-1;
		c=getchar();
	}while(isdigit(c)){
		x=(x<<1)+(x<<3)+c-48;
		c=getchar();
	}
	return f*x;
} 
const int N=2e5+10;
int n,q;
string s1[N][2];
string s2[N][2];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read();
	q=read();
	for(int i=1;i<=n;i++){
		cin>>s1[i][0];
		cin>>s1[i][1];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		cin>>s2[i][0];
		cin>>s2[i][1];
		if(s1[i][0]==s2[i][0]&&s1[i][1]==s2[i][1]) ans++;
		ans+=n/4;
		cout<<ans<<"\n";
	}
	return 0;
}
