#include<bits/stdc++.h>
using namespace std;
namespace A{
	int n,m,ans,c[510];
	string s;
	bool cmp(int x,int y){
		return x>y;
	}
	int main(){
		freopen("replace.in","r",stdin);
		freopen("replace.out","w",stdout);
		cin>>n>>m>>s;
		for(int i=1;i<=n;i++){
			cin>>c[i];
		}
		if(m==1){
			cout<<n;
			return 0;	
		}
//		sort(c+1,c+n+1,cmp);
//		for(int i=1;i<=n;i++){
//			for
//		}
		cout<<ans;
		return 0;
	}
}
int main(){
	return A::main();
}