#include<bits/stdc++.h>
using namespace std;
int a,s;
struct node {
	string d,f;
} p[100010];
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>a>>s;
	for(int i=0; i<a; i++) {
		string z,x;
		cin>>z>>x;
		p[i].d=z,p[i].f=x;
	}
	while(s--) {
		string g,h;
		cin>>g>>h;
		if(a>=10000){
			puts("0");
			continue;
		}
		int ans=0,n=g.size();
		for(int i=0; i<n; i++) {
			string u="";
			for(int j=i; j<n; j++) {
				u+=g[j];
				bool w=0;
				for(int k=0; k<a; k++) {
					if(p[k].d[j-i]==g[j-i]) {
						w=1;
						break;
					}
				}
				if(w) {
					for(int k=0; k<a; k++) {
						if(p[k].d==u) {
							string o="";
							for(int m=0; m<i; m++) {
								o+=g[m];
							}
							o+=p[k].f;
							for(int m=j+1; m<n; m++) {
								o+=g[m];
							}
							if(o==h)ans++;
						}
					}
				}else break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
