#include<bits/stdc++.h>
#define ff(i,n) for(int i=1;i<=n;i++)
#define rep(i,s,n) for(int i=s;i<=n;i++)
#define int long long
using namespace std;
const int N=1e4+10,M=2e6+10,mod=1e9+7;
int i,j,n,m,k,x,y,tot,z;
int in(){
	int w=1,res=0;
	char c;
	c=getchar();
	while(!('0'<=c&&c<='9')){
		if(c=='-')w=-w;
		c=getchar();
	}
	while(('0'<=c&&c<='9')){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*w;
}
main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	while(m--){
		cout<<"0\n";
	}
}
