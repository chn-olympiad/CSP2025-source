#include <bits/stdc++.h>

#define fst first
#define sec second
#define pb push_back
#define mp make_pair

using namespace std;

using ll = long long;
using ull = unsigned long long;
using i128 = __int128;
using p_q = priority_queue<int>;

map<pair<string,string>,int> rts,rtp; 

const int N = 5e6+50;

int nd[N][26],cnt;
int cnt2,hd[N],nxt[N],nv[N];
void tadd(int u,int k){
	nxt[++cnt]=hd[u];nv[cnt]=k,hd[u]=cnt;
}
int ti(int u,string s,int k){
	u=u?u:++cnt;
	int nu=u;
	for(int i=0;i<s.size();i++){
		if(!nd[u][s[i]-'a']) nd[u][s[i]-'a']=++cnt;
		u=nd[u][s[i]-'a'];
	}
	tadd(u,k);
//	cout<<"AK:"<<u<<" "<<k<<endl;
	return nu;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		string s3,s4,s5,s6;
		int l=0,r=-1;
		for(int j=0;j<s1.size();j++){
			if(s1[j]!=s2[j]){
				l=j;break;
			}
		}
		for(int j=l-1;j>=0;j--)
			s5.pb(s1[j]);
		for(int j=s1.size()-1;j>=0;j--){
			if(s1[j]!=s2[j]){
				r=j;break;
			}
		}
		for(int j=r+1;j<s1.size();j++)
			s6.pb(s1[j]);
		for(int j=l;j<=r;j++){
			s3.pb(s1[j]),s4.pb(s2[j]);
		}
//		cout<<"ST:"<<s3<<" "<<s4<<" "<<s5<<" "<<s6<<endl;
		rts[mp(s3,s4)]=ti(rts[mp(s3,s4)],s5,i),rtp[mp(s3,s4)]=ti(rtp[mp(s3,s4)],s6,i);
//		cout<<"WN:"<<rts[mp(s3,s4)]<<" "<<rtp[mp(s3,s4)]<<endl;
	}
	for(int i=1;i<=q;i++){
		string t1,t2,t3,t4,t5,t6;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){
			cout<<"0\n";continue;
		}
		int l=0,r=-1;
		for(int j=0;j<t1.size();j++){
			if(t1[j]!=t2[j]){
				l=j;break;
			}
		}
		for(int j=l-1;j>=0;j--)
			t5.pb(t1[j]);
		for(int j=t1.size()-1;j>=0;j--){
			if(t1[j]!=t2[j]){
				r=j;break;
			}
		}
		for(int j=r+1;j<t1.size();j++)
			t6.pb(t1[j]);
		for(int j=l;j<=r;j++){
			t3.pb(t1[j]),t4.pb(t2[j]);
		}
		ll ans=0;
		map<int,int> qwq;
		int u1=rts[mp(t3,t4)],u2=rtp[mp(t3,t4)];
//		cout<<"WN:"<<u1<<" "<<u2<<endl;
		int u=u1;
//		cout<<"FK:"<<t3<<" "<<t4<<" "<<t5<<" "<<t6<<endl;
		for(int v=hd[u];v;v=nxt[v]) qwq[nv[v]]++;
		for(int j=0;j<t5.size();j++){
			u=nd[u][t5[j]-'a'];
//			cout<<"ER:"<<u<<" "<<lf[u]<<endl;
			if(!u) break;
			for(int v=hd[u];v;v=nxt[v]) qwq[nv[v]]++;
		}
		u=u2;
		for(int v=hd[u];v;v=nxt[v]) if(qwq[nv[v]]) ans++;
		for(int j=0;j<t6.size();j++){
			u=nd[u][t6[j]-'a'];
			if(!u) break;
			for(int v=hd[u];v;v=nxt[v]) if(qwq[nv[v]]) ans++;
		}
		cout<<ans<<'\n';
	}

	return 0;
}

