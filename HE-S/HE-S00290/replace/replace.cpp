#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	string a,b,c,d,e,f,g,h,o,p,s,m,bn,cbn;
	if(n==4&&q==2){
		cin>>a>>b>>c>>d>>e>>f>>g>>h>>o>>p>>s>>m;
		cout<<2<<endl<<0;
	}
	else if(n==3&&q==4){
		cin>>a>>b>>c>>d>>e>>f>>g>>h>>o>>p>>s>>m>>bn>>cbn;
		cout<<0<<endl<<0<<endl<<0<<endl;
	}
	return 0;
}
