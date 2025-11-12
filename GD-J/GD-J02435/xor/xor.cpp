#include<bits/stdc++.h>
using namespace std;
int a[500001],s[500001];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	register int n,k,i,j,ans=0,cnt=0,maxn=0;
	register bool bj;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		maxn=max(maxn,a[i]);
	}
	if(maxn<=1&&k<=1){
		if(k==1){
			for(i=1;i<=n;++i)
				if(a[i])++ans;
		}
		else{
			for(i=1;i<=n;++i)
				if(a[i]==0)++ans;
				else if(a[i]==a[~-i]&&a[i]){
					if(a[-~i]==0)++ans;
					++ans,++i;
				}
		}
	}
	else if(maxn<=255&&k<=255){
		int bg1[256],bg2[256];
		memset(bg1,0,sizeof(bg1));
		for(i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]==k){
				++ans,cnt=0;
				memset(bg1,0,sizeof(bg1));
			}
			else{
				if(bg1[k^a[i]]){
					++ans,cnt=0;
					memset(bg1,0,sizeof(bg1));
				}
				else{
					memset(bg2,0,sizeof(bg2));
					for(j=1;j<=cnt;++j)
						bg2[a[i]^s[j]]=bg1[s[j]],s[j]^=a[i];
					for(j=0;j<=255;++j)
						bg1[j]=bg2[j];
					if(bg1[a[i]]==false){
						bg1[a[i]]=true;
						s[++cnt]=a[i];
					}
				}
			}
		}
	}
	else for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]==k)
			++ans,cnt=0;
		else{
			bj=false;
			for(j=1;j<=cnt;++j)
				if((s[j]^a[i])==k){
					bj=true;
					break;
				}
				else s[j]=s[j]^a[i];
			if(bj)
				cnt=0,++ans;
			else s[++cnt]=a[i];
		}
	}
	printf("%d",ans);
	return 0;
}
