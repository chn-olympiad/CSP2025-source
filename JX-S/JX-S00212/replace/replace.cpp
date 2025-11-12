#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define ull unsigned long long
pair<ull,ull> a[N];
int length[N];
const int M=5e6+5;
const ull base=131;
const ull Mod=998244353;
void Hash(string s,ull* Ha){
	for(int i=1;i<(int)s.size();i++){
		Ha[i]=((Ha[i-1]*base)%Mod+s[i]-'a'+1)%Mod;
	}
}
ull powb[M];
void init(int p){
	powb[0]=1;
	for(int i=1;i<=p;i++){
		powb[i]=(powb[i-1]*base)%Mod;
	}
}
ull get(int l,int r,ull* Ha){
	
	int res=(Ha[r]+Mod-(Ha[l-1]*powb[r-l+1])%Mod)%Mod;
	return res;
}
ull Hashs(string s){
	ull res=0;
	for(int i=1;i<(int)s.size();i++){
		res=((res*base)%Mod+s[i]-'a'+1)%Mod;
	}
	return res;
}
ull h1[M];
ull h2[M];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	init(5000000);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s,t;
		cin>>s>>t;
		s=" "+s;
		t=" "+t;
		length[i]=(int)s.size();
		a[i]={Hashs(s),Hashs(t)};
	}
	while(q--){
		string qs,qt;
		cin>>qs>>qt;
		qs=" "+qs;
		qt=" "+qt;
		if(qs.size()!=qt.size()){
			cout<<"0\n";
			continue;
		}
		Hash(qs,h1);
		Hash(qt,h2);
		int ans=0;
		int qlen=qs.size()-1;
		for(int i=1;i<=n;i++){
			for(int lx=0;lx<=(int)qs.size()-length[i];lx++){
				if(get(lx+1,lx+length[i]-1,h1)==a[i].first){
					if(get(lx+1,lx+length[i]-1,h2)==a[i].second){
						if(get(lx+length[i],qlen,h1)==get(lx+length[i],qlen,h2)){
							ans++;
						}
					}
				}
				
				if(qt[lx+1]!=qs[lx+1]){
					break;
				}
			}
		}
		cout<<ans<<"\n";
	}
}
