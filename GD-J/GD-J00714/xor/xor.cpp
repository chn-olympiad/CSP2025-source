#include<bits/stdc++.h>
using namespace std;
int n,k,f,ans,last,a[500001],s[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]=s[i-1]^a[i];
	}
	for(int l=1;l<=n;){
		for(int r=l;r<=n;r++){
			if((s[r]^s[l-1])==k){
				ans++;
				last=r;
				f=1;
				break;
			}
		}
		if(f==1)l=last+1,f=0;
		else l++;
	}
	printf("%d",ans);
	return 0;
}
