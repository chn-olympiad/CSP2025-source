//GZ-S00197 遵义市第四中学 戴文博
#include <bits/stdc++.h>
using namespace std;
long long n,t;
struct f {
	long long club,value,man;
} s[400010];
long long S[100005];
long long cl[4];
bool cmp(f x,f y) {
	return x.value>=y.value;
}
long long len=0;
long long ans=0;
int main() {
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--) {
		bool f=0;
		memset(S,0,sizeof(S));
		memset(cl,0,sizeof(cl));
		scanf("%d",&n);
		len=0;
		for(long long i=1; i<=n; i++) {
			long long x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if(z||y)f=1;
			len++;
			s[len].value=x;
			s[len].club=1;
			s[len].man=i;
			len++;
			s[len].value=y;
			s[len].club=2;
			s[len].man=i;
			len++;
			s[len].value=z;
			s[len].club=3;
			s[len].man=i;
		}
		sort(s+1,s+1+(3*n),cmp);
		long long sum=0;
		ans=0;
		if(f){
		sum=0;
		ans=0;
		for(long long i=1; i<=3*n; i++) {
			if(S[s[i].man])continue;
			if(cl[s[i].club]==n/2)continue;
			if(sum==n)break;
			sum++;
			ans=ans+s[i].value;
			cl[s[i].club]++;
			S[s[i].man]=1;
		}
	    }else{
	    	for(long long i=1;i<=n/2;i++){
	    		ans+=s[i].value;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}

