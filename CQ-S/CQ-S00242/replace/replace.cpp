#include<bits/stdc++.h>
#define ll long long
#define endl "\n"
#define debug(x) cerr<<"debug: "<<#x<<" = "<<x<<endl
using namespace std;
namespace code{
	inline ll read(){
		int f=1;ll x=0;char ch=getchar();
		while(ch<'0'||ch>'9'){
			if(ch=='-') f=-f;
			ch=getchar();
		}
		while(ch>='0'&&ch<='9'){
			x=x*10+(ch-'0');
			ch=getchar();
		}
		return f*x;
	}
	int random(int l,int r){
		int ran=rand()*rand();
		return ran%(r-l+1)+l;
	}
	signed main(){
		cin>>n>>m;
		srand(time(0));
		for(int i=1;i<=m;i++) cout<<random(1,100)<<"\n";
		return 0;
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	return code::main();
}
