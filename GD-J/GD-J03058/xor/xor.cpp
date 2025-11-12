#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],s[N];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;scanf("%d%d",&n,&k);
	int ans=0;
	memset(s,0,sizeof s);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	int st=1,ed;
	for(ed=1;ed<=n;ed++){
		for(int i=st;i<=ed;i++){
			int l=s[ed]^s[i-1];
			if(l==k){
				ans++;
				st=ed+1;
				break;
			}
		}
	}
	printf("%d",ans);
	
	return 0;
}
