#include <iostream>
#include <cstdio>
#define N 200005
#define M 5000005
using namespace std;
int n,q;
string s1[N],s2[N],t1,t2;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1; i<=n; i++) {
		cin>>s1[i]>>s2[i];
	}
	while(q--) {
		int ans=0;
		cin>>t1>>t2;
		for(int i=1; i<=n; i++) {
			string s=s1[i];
			for(int j=0;j<t1.size();j++){
				int jj=j,kk=0;
				while(t1[jj]==s[kk]&&jj<t1.size()&&kk<s.size()){
					++jj;
					++kk;
				}
				if(kk==s.size()){
					string tmp=t1;
					for(int l=kk-s.size(),p=0;l<kk;l++,p++){
						tmp[l]=s2[i][p];
					}
					if(tmp==t2){
						++ans;
						break;
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
