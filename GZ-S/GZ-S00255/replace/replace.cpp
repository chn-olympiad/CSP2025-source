#include<bits/stdc++.h>
using namespace std;
struct Node{
	string a,b;
};
Node q[10000],w[10000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,p;
	string y,x,z;
	scanf("%d %d",&n,&p);
	for(int i=1;i<=n;++i){
		cin>>q[i].a>>q[i].b;
	}
	for(int i=1;i<=p;++i){
		cin>>w[i].a>>w[i].b;
	}
	int ans=0;
	
	for(int i=1;i<=p;++i){
		for(int j=1;j<=n;++j){
			y=q[i].b;
			int e1=w[i].b.find(y);int e2=w[i].b.find(y[y.size()-1],e1+y.size()-1);
			string o=w[i].b.substr(0,w[i].b.size()-1);
			if(y==o){
				ans++;	
				continue;
			}
			x="";
			if(e1>0) x=w[i].a.substr(0,e1-1);
			z="";
			if(e2<w[i].b.size()-1) z=w[i].a.substr(e2+1,w[i].b.size()-1);
			cout<<x<<'\n';
			cout<<e1<<' '<<e2<<'\n';
			if(x+y+z==w[i].b){
				ans++;
			}
		}
		cout<<ans<<'\n';
		ans=0;
	}
	
	return 0;
}
