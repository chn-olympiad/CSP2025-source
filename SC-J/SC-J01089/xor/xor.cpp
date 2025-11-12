#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int S=1.5e6+5;
int n,k,a[N],s[N],cnt[S],ans,tag[S],nw;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	cnt[0]++;
	for(int i=1;i<=n;i++){
		int t=s[i]^k;
		if(cnt[t]&&tag[t]==nw){
			ans++; nw++;
		}
		if(tag[s[i]]!=nw)cnt[s[i]]=1,tag[s[i]]=nw;
		else cnt[s[i]]++,tag[s[i]]=nw;
	}
	printf("%d",ans);
	return 0;
}