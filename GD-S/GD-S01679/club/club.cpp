#include<bits/stdc++.h>
using namespace std;
struct a{
	int b,c,d;
}e[11];
bool s(a f,a g){
	return f.b>g.b;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>e[j].b>>e[j].c>>e[j].d;
		}
		int sum=0;
	    sum=max(e[1].b+e[2].c,max(e[1].b+e[2].d,max(e[1].c+e[2].b,max(e[1].c+e[2].d,max(e[1].d+e[2].b,e[1].d+e[2].c)))));
		cout<<sum<<endl;
	}
	return 0;
}
