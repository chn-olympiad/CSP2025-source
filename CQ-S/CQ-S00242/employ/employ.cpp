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
		srand(time(0));
		cout<<random(1,10000);
		return 0;
	}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	return code::main();
}
