#include<bits/stdc++.h>
using namespace std;
int n,q,K;
string S[100005],SS[100005],s[100005],ss[100005];
string k,kk;
map<string,int> H;
map<string,int> I;
bool l=false;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>S[i]>>SS[i];
		H[S[i]]+=1;
		I[SS[i]]+=1;
	}
	for(int i=1;i<=q;i++){
		cin>>s[i]>>ss[i];
	}
	for(int i=1;i<=q;i++){
		int ans=0;
		if(s[i].size()==ss[i].size()){
			if(H[s[i]]>=1&&I[ss[i]]>=1) ans+=min(H[s[i]],I[ss[i]]);//全文替换特判
			for(int j=1;j<s[i].size();j++){
				if(s[i][j]!=ss[i][j]&&l!=true&&K<1){
					l=true;
					k=s[i][j];
					kk=ss[i][j];
				}
				if(l){
					k+=s[i][j];
					kk+=ss[i][j];
					if(H[k]>=1&&I[kk]>=1&&s[i+1]==ss[i+1]) ans+=min(H[k],I[kk]);
				}
			}
			cout<<ans<<"\n";	
		}
		else{
			cout<<0<<"\n";
		}
	}
	return 0;
}