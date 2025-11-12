//GZ-S00363 毕节梁才学校 罗悦辉
#include<bits/stdc++.h>
using namespace std;
int n,q;
set<string> tbl1,tbl2;
string u,v,x,y;

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++) {
		cin>>u>>v;
		tbl1.insert(u),tbl2.insert(v);
	}

	while(q--) {

		int cnt=0;
		cin>>u>>v;
		
		if(u.size()!=v.size()){
			puts("0");
			continue;
		}
		
		for(int i=0; i<(int)u.size(); i++) {
			for(int j=1; i+j<=(int)u.size(); j++) {
				x=u.substr(i,j);
				y=v.substr(i,j);
				if((tbl1.find(x)!=tbl1.end())&&(tbl2.find(y)!=tbl2.end())) {
					if(i!=0) x=u.substr(0,i),y=v.substr(0,i);
					if(i==0||x==y) {
						x=u.substr(i+j),y=v.substr(i+j);
						if(x==y) {
							cnt++;
						}
					}
				}
			}
		}

		printf("%d\n",cnt);

	}

	return 0;
}
