#include<bits/stdc++.h>
using namespace std;
inline int read(){
	register char c=getchar();
	register int x=0;
	for(;(c<48)||(c>57);c=getchar());
	for(;(47<c)&&(c<58);c=getchar()){
		x=(x<<1)+(x<<3)+c-48;
	}
	return x;
}
#define ll long long
char p1[200010],p2[200010];
const ll pw=31,mod=1e9+7;
ll f[200010];
vector<int>L[200010],R[200010];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n=read(),q=read(),len,mn,mx,ans;
	bool fl;
	ll sum;
	for(register int i=1;i<=n;++i){
		scanf("%s",p1+1);
		len=strlen(p1+1);
		scanf("%s",p2+1);
		mx=0;mn=5e6;
		for(register int j=1;j<=len;++j){
			if(p1[j]!=p2[j]){
				mx=max(mx,j);
				mn=min(mn,j);
			}
		}
		f[i]=0;
		for(register int j=mn;j<=mx;++j){
			f[i]=(f[i]*pw*pw+(p1[j]-'a')*pw+(p2[j]-'a'));
		}
		for(register int j=mn-1;j>=1;--j){
			L[i].push_back(p1[j]-'a');
		}
		for(register int j=mx+1;j<=len;++j){
			R[i].push_back(p1[j]-'a');
		}
	}
	while(q--){
		scanf("%s",p1+1);
		len=strlen(p1+1);
		scanf("%s",p2+1);
		mx=0;mn=5e6;
		for(register int j=1;j<=len;++j){
			if(p1[j]!=p2[j]){
				mx=max(mx,j);
				mn=min(mn,j);
			}
		}
		sum=0;
		for(register int j=mn;j<=mx;++j){
			sum=(sum*pw*pw+(p1[j]-'a')*pw+(p2[j]-'a'));
		}
		ans=0;
		for(register int i=1;i<=n;++i){
			if(f[i]==sum){
				if((((int)L[i].size())>mn-1)||((int)(R[i].size())>len-mx)){
					continue;
				}
				fl=true;
				for(register int j=1;j<=(int)L[i].size();++j){
					if(L[i][j-1]!=(p1[mn-j]-'a')){
						fl=false;
						break;
					}
				}
				if(fl){
					for(register int j=1;j<=(int)R[i].size();++j){
						if(R[i][j-1]!=(p1[mx+j]-'a')){
							fl=false;
							break;
						}
					}
				}
				if(fl)++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
