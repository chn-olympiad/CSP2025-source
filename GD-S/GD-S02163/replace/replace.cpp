#include<bits/stdc++.h>
using namespace std;
int n,q,ns,nt,tt,xx,yy,z,zz,a,b,c,d,e,f,aa,bb,cc,dd,ee;
string s,t,x[100000],y[100000];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>x[i]>>y[i],x[i]="0"+x[i],y[i]="0"+y[i];
	for(int i=1;i<=q;i++){
		cin>>s>>t;
		s="0"+s;
		t="0"+t;
		bb=0;
		for(int j=1;j<=n;j++){
			for(int k=1;k<s.size();k++){
				aa=1;
				for(int w=1;w<x[j].size();w++){
					if(s[k+w-1]!=x[j][w]){
						aa=0;
						break;
					}
				}
				if(aa){
					aa=1;
					for(int i=1;i<k;i++){
						if(s[i]!=t[i]){
							aa=0;
							break;
						}
					}
					if(aa){
						aa=1;
						for(int w=1;w<y[j].size();w++){
							if(t[k+w-1]!=y[j][w]){
								aa=0;
								break;
							}
						}
						c=s.size();
						d=x[j].size();
						e=y[j].size();
						f=t.size();
						if(aa==1&&c-d+e==f) {
							aa=1;
							for(int w=k+x[j].size()-1;w<s.size();w++){
								if(s[w]!=t[w-x[j].size()+y[j].size()]){
									aa=0;
									break;
							}
							}
							bb+=aa;
						}
					}
				}
			}
		}
		printf("%d\n",bb);
	}
} 
