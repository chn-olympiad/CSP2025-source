#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,ans,l,_l,p;
char t1[10005],t2[10005],s1[20005][10005],s2[20005][10005],x[10005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%s",s1[i]);
		scanf("%s",s2[i]);
	}
	while(q--){
		scanf("%s",t1);
		scanf("%s",t2);
		ans=0;
		for(int i=1;i<=n;i++){
			l=strlen(t1);
			p=0;
			for(int j=0;j<l;j++) x[j]=t1[j];
			for(int j=0;j<l;j++){
				if(x[j]==s1[i][0]){
					p++;
					_l=strlen(s1[i]);
					for(int k=0;k<_l;k++){
						if(x[j+k]==s1[i][k]) x[j+k]=s2[i][k];
						else break;
					}
					j+=_l;
				}
			}
			ans++;
			for(int j=0;j<l;j++){
				if(x[j]!=t2[j]){
					ans--;
					break;
				}
				if(p!=1){
					ans--;
					break;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
// 2025-11-01/17:27
//²ÝÉñµÄÐÅÍ½+1 Q-Q 
