#include <iostream>
#include <string>
#include <cstring>
#define int unsigned long long
using namespace std;
const int p=137,N=2e5+7,M=5e6+7;
string s1,s2;
int n,q,a[N],b[N],len[N],k1[M],k2[M],rev[M];
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	rev[0]=1;
	for(int i=1;i<=M-7;i++)rev[i]=rev[i-1]*p;
	for(int i=1;i<=n;i++) {
		cin>>s1>>s2;
		len[i]=s1.length();
		for(int j=0;j<len[i];j++) {
			a[i]=a[i]+(s1[j]-'a')*rev[j];
			b[i]=b[i]+(s2[j]-'a')*rev[j];
		}
	}
	
	while(q--) {
		cin>>s1>>s2;
		int ans=0;
		if(s1.length()!=s2.length()) {
			printf("0\n");
			continue;
		}
		int ln=s1.length(),st,en;
		k1[0]=s1[0]-'a';k2[0]=s2[0]-'a';
		for(int i=1;i<ln;i++) {
			k1[i]=k1[i-1]+(s1[i]-'a')*rev[i];
			k2[i]=k2[i-1]+(s2[i]-'a')*rev[i];
		}
		for(int i=0;i<ln;i++) {
			if(s1[i]!=s2[i]) {
				st=i;
				break;
			}
		}
		for(int i=ln-1;i>=0;i--) {
			if(s1[i]!=s2[i]) {
				en=i;
				break;
			}
		}
		for(int i=1;i<=n;i++) {
			if(len[i]<en-st+1)continue;
			int x=en+1>=len[i]?en+1-len[i]:0;
			for(int j=x;j<=st;j++) {
				if(j+len[i]-1>=ln)break;
				int l=j,r=j+len[i]-1;
				if((a[i]*rev[l]==(k1[r]-(l==0?0:k1[l-1])))&&(b[i]*rev[l]==(k2[r]-(l==0?0:k2[l-1]))))ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
