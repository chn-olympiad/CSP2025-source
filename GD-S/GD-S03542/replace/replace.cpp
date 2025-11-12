#include<bits/stdc++.h>
using namespace std;
int n,q;
string a,b;
map<string,string> my;
void check(){
	int res=0,X,Y,A=a.size(),B=b.size();
	for(pair<string,string> t:my){
		string x,y;
		x=t.first;y=t.second;
		X=x.size(),Y=y.size();
		if(X>A || (X-Y)+A!=B) continue;
		string r,e,h,chk;
		for(int i=0;i<=(A-X);i++){
			chk=a.substr(i,X);
			if(chk!=x) continue;
			if(i)
				r=a.substr(0,i);
			if(A-i-1)
				e=a.substr(i+X,A-i-1);
//			cout<<a<<' '<<b<<' '<<x<<' '<<i<<"test:\n";
//			cout<<r<<w<<e<<'\n';
			h=r+y+e;
			if(h==b) res++;
		}
	}
	printf("%d\n",res);
	return;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		my[a]=b;
	}
	while(q--){
		cin>>a>>b;
		check();
	}
	return 0;
}
