#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pair;
void read(int& x){
	x=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)){
		x=(x<<1)+(x<<3)+(c^'0');
		c=getchar();
	}
}
int n,q;
map<string,string> f;
map<string,int> ff;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string x,y;
		cin>>x>>y;
		f[x]=y;
		ff[x]++;
	} 
	while(q--){
		ll ans=0;
		string x,y;
		cin>>x>>y;
		for(int i=0;i<x.size();i++){
			string s,ss;
			s=ss="";
			string sr="",ssr="";
			bool F=0; 
			for(int j=i;j<=x.size();j++){
				s+=x[j];
				ss+=y[j];
				bool flg=1;
				
				for(int k=j+1;k<x.size();k++){
					if(F==1) break;
					if(x[k]!=y[k]){
						flg=0;
						break; 
					} 
				}if(f[s]==ss) ans+=flg*ff[s];
				F=flg;
			}
			if(x[i]!=y[i]) break;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

