#include<bits/stdc++.h>
using namespace std;
struct Node{
	int a,b,c;
	bool operator<(const Node &x)const{
		return a>x.a;
	}
};
int T;
Node g[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>g[i].a>>g[i].b>>g[i].c;
		}
		sort(g+1,g+n+1);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=g[i].a;
		}
		cout<<ans<<"\n";
	}
}
