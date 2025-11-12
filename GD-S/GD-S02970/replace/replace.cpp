#include<bits/stdc++.h>
#define ull unsigned long long
#define P pair<int,int>
#define Pz pair<string,int>
using namespace std;
bool MB1;
const int N=2e5+10;
const ull Bas=31,HH=1e9+7;
int n,q;
char a[N];
unordered_map<ull,int> as;
unordered_map<ull,int> id;
unordered_map<ull,int> to2[N];
unordered_map<ull,int> H2[N];
unordered_map<ull,bool>vis[N];
unordered_map<ull,int> num;
int cnt,cnt2;
vector<P> p[N];
ull geth(int l,int r,string &s,int op){
	if(op==0){
		ull ans=0;
		for(int i=l;i<=r;i++) ans=ans*Bas+s[i];
		return ans;		
	}
	else{
		ull ans=0;
		for(int i=l;i>=r;i--) ans=ans*Bas+s[i];
		return ans;
	}
}

vector<string> sp;
bool cmp(string &s1,string &s2){
	return s1.size()<s2.size();
}
void build(int rt){
	num.clear();
	sort(sp.begin(),sp.end(),cmp);
	//if(rt==3) cout<<rt<<" "<<sp.size()<<sp[0]<<endl;
	for(int i=0;i<sp.size();i++){
		string s1=sp[i];
		ull ans=0;
		ull las=0;vis[rt][ans]=1;
		for(int i=0;i<s1.size();i++){
			ans=ans*Bas+s1[i];
			vis[rt][ans]=1;
		}
		num[ans]++;H2[rt][ans]++,vis[rt][ans]=1;
		//if(rt==3) cout<<rt<<" "<<sp[i]<<" "<<ans<<endl; 
	}
	for(int i=0;i<sp.size();i++){
		string s1=sp[i];
		ull ans=0;
		ull las=0;
		for(int i=0;i<s1.size();i++){
			ans=ans*Bas+s1[i];
			H2[rt][ans]=H2[rt][las]+num[ans];
			vis[rt][ans]=1;
			las=ans;
		}
		//num[ans]++;H2[rt][ans]++;vis[rt][ans]=1;
		//cout<<rt<<" "<<sp[i]<<" "<<ans<<" "<<H2[rt][ans]<<" "<<num[ans]<<endl; 
	}
}
ull st[N];
string s22[N];
int L,R;
int ddnum;
int getans(int rt){
	//cout<<"now is"<<rt<<endl;
	//if(rt==3)cout<<rt<<" "<<st[R]<<" "<<H2[rt][st[R]]<<" "<<vis[rt][st[0]]<<" "<<H2[rt][st[0]]<<endl;
	if(rt==0) return 0;
	int l=L,r=R,ans=l;
	while(l<=r){
		int mid=(l+r)>>1;
		if(vis[rt][st[mid]]!=0) ans=mid,l=mid+1;
		else r=mid-1;
	}
	//if(rt==3) cout<<ans<<" "<<rt<<" "<<L<<" "<<vis[rt][st[L]]<<" "<<st[L]<<" "<<H2[rt][st[L]]<<endl;
	//cout<<rt<<" "<<ans<<" "<<(ans==-1?-1:H2[rt][ans])<<endl;
	if(ans==-1) return 0;
	return H2[rt][st[ans]];
}
bool MB2;
void start(){
	#ifdef GNF
	freopen("1.in","r",stdin);
	#endif
}
void end(){
	cerr<<endl;
	cerr<<fixed<<setprecision(3)<<clock()/CLOCKS_PER_SEC*1000.0<<"ms"<<endl;
	cerr<<abs(&MB2-&MB1)/1024.0/1024.0<<"MB"<<endl;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//freopen("1.out","w",stdout);
	start();
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;cin>>s1>>s2;
		s22[i]=s2; 
		int len=s1.size(),l=len,r=0;
		for(int i=0;i<len;i++){
			if(s1[i]!=s2[i]) l=min(l,i),r=max(r,i);
		}
		ull s=geth(l,r,s1,0)+geth(l,r,s2,0)*HH,t1=geth(l-1,0,s1,1);
		//cout<<i<<" "<<s<<" "<<t1<<endl;
		//if(i==3) cout<<l<<" "<<r<<" "<<s<<" "<<" "<<t1<<endl;
		if(!id[s]) id[s]=++cnt;
		if(!to2[id[s]][t1]) to2[id[s]][t1]=++cnt2;
		p[to2[id[s]][t1]].push_back({i,r+1});
	}
	for(int i=1;i<=cnt2;i++){
		sp.clear();
		for(int j=0;j<p[i].size();j++){
			int id=p[i][j].first,dr=p[i][j].second;
			string ss="";
			for(int k=dr;k<s22[id].size();k++){
				ss+=s22[id][k];
			}
			//cout<<i<<" "<<p[i][j].first<<endl;
			sp.push_back(ss);
		}
		//if(i==3) cout<<sp.size()<<endl;
		build(i);
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size(),l=len,r=0;
		//if(s1.size()!=s2.size()) cerr<<1<<endl;
		for(int i=0;i<len;i++){
			if(s1[i]!=s2[i]) l=min(l,i),r=max(r,i);
		}
		int idz=id[geth(l,r,s1,0)+geth(l,r,s2,0)*HH];
		st[0]=0;L=0,R=0;
		for(int i=1,dr=r+1;dr<s1.size();i++,dr++){
			st[i]=st[i-1]*Bas+s1[dr];R=max(R,i);
		}
		int ans=getans(to2[idz][0]);
		ull sum=0;
		int dnum=i;
		for(int i=l-1;i>=0;i--){
			sum=sum*Bas+s1[i];
			//cout<<i<<" "<<sum<<" "<<idz<<endl;
			ans+=getans(to2[idz][sum]);
			//cout<<to2[idz][sum]<<" "<<getans(to2[idz][sum])<<endl;
		}
		cout<<ans<<endl;
	}
	end();
}

