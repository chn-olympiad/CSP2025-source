//30
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+10;
int n,q,ans;
string s1[MAXN],s2[MAXN],st1,st2;
int dff[MAXN],fr[MAXN],nd[MAXN],dfft,frt,ndt;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s1[i]>>s2[i];
		for(int j=0;j<s1[i].length();j++){
			if(s1[i][j]=='b'){
				dff[i]+=j;fr[i]=j;
			}
			if(s2[i][j]=='b'){dff[i]-=j;nd[i]=j;
			}
		}
	}
	while(q--){
		ans=0;frt=-1;dfft=0;frt=0;
		cin>>st1>>st2;
		for(int j=0;j<st1.length();j++){
			if(st1[j]=='b'){
				dfft+=j;frt=j;
			}
			if(st2[j]=='b'){dfft-=j;ndt=j;
			}
		}
		for(int i=0;i<n;i++){
			if(frt>=fr[i]&&dfft==dff[i]&&(st1.length()+fr[i]>=frt+s1[i].length()))ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
