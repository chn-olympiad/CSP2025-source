#include<bits/stdc++.h>
#define int long long
#define fors(i,a,b) for(int i=a;i<=b;i++)
#define forr(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
int n,q;
unordered_map<string,int>mp;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q;
	while(n--){
		int ut=0,dt=0;
		string u,v;
		cin>>u>>v;
		if(u==v)continue;
		int sz=u.size();
		fors(i,0,sz-1){
			if(u[i]!=v[i]){
				ut=i;
				break;
			}
		}
		forr(i,sz-1,0){
			if(u[i]!=v[i]){
				dt=i;
				break;
			}
		}
		string w1="";
		string w2="";
		fors(i,ut,dt){
			w1+=u[i];
			w2+=v[i];
		}
		string w=w1+w2;
		mp[w]++;
	}
	while(q--){
		int ut=0,dt=0;
		string u,v;
		cin>>u>>v;
		int sz=u.size();
		fors(i,0,sz-1){
			if(u[i]!=v[i]){
				ut=i;
				break;
			}
		}
		forr(i,sz-1,0){
			if(u[i]!=v[i]){
				dt=i;
				break;
			}
		}
		string w1="";
		string w2="";
		fors(i,ut,dt){
			w1+=u[i];
			w2+=v[i];
		}
		string w=w1+w2;
		if(mp.count(w)){
			cout<<mp[w]<<'\n';
		}else cout<<"0\n";
	}
	return 0;
}