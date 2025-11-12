#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
#define ll long long
#define f first
#define g second

ll m,n;
ll T;
pair<string,string> s[N];
int sfront[N],send[N];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>T;
	for(int i=1;i<=n;i++){
		string kl,kp;
		cin>>kl>>kp;
		s[i].f=kl,s[i].g=kp;
		int u=0;
		while((u<(int)kl.size())&&(s[i].f[u]==s[i].g[u])){
			sfront[i]=++u;
		}
		int w=0;
		while(w<(int)kl.size()&&s[i].f[s[i].f.size()-w-1]==s[i].g[s[i].f.size()-w-1]){
			sfront[i]=++w;
		}
	}
	for(int qwertyuiop=1;qwertyuiop<=T;qwertyuiop++){
		ll ans=0;
		string old,nnew;
		cin>>old>>nnew;
		int l=old.size();
		for(int i=1;i<=n;i++){
			int st=0;
			bool cana=1;
			for(int j=0;j<l;j++){
				if(st>(int)s[i].f.size()){
					if(old[j]!=nnew[j]){
						cana=0;
						break;
					}
					else continue;
				}
				//
				if((st>0&&old[j]!=s[i].f[st])||(st>0&&nnew[j]!=s[i].g[st])){
					cana=0;
					break;
				}
				if(st)st++;
				//kksc kksd
				if(!st&&old[j]!=nnew[j]){
					if(s[sfront[i]].f[sfront[i]-1]==old[j]&&s[sfront[i]].f[sfront[i]-1]==nnew[j]){
						bool kada=1;
						for(int ii=0;ii<sfront[i];ii++){
							if(s[i].f[ii]!=old[j+ii-sfront[i]]||s[i].g[ii]!=nnew[j+ii-sfront[i]]){
								kada=0;break;
							}
						}
						if(kada){
							cana=0;
							break;
						}
						else st=sfront[i]-1;
					}//no st
					else if((old[j]!=s[i].f[st]&&old[j]!=nnew[j])||(nnew[j]!=s[i].g[st]&&old[j]!=nnew[j])){
						cana=0;
						break;
					}
					else st=1;
				}
			}
			if(cana)ans++;
		}
		printf("%lld\n",ans);
	}
	return 0;
}