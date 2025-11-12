#include<bits/stdc++.h>
using namespace std;
ifstream fin("club.in");
ofstream fout("club.out");
#define cout fout
#define cin fin 
typedef long long ll;
priority_queue<ll,vector<ll>,less<ll> >st;
vector<ll>club[3];
priority_queue<ll,vector<ll>,greater<ll> >gw;
vector<ll>vlt[3];
bool vst[100100];
int main(){
	ll T;cin>>T;
	ll n;
	while(T--){
		memset(vst,0,sizeof(vst));
		while(!st.empty())st.pop();
		while(!gw.empty())gw.pop();
		vlt[0].clear();vlt[1].clear();vlt[2].clear();
		club[0].clear();club[2].clear();club[1].clear();
		ll ans=0;
		cin>>n;
		vlt[0].push_back(0);
		vlt[1].push_back(0);
		vlt[2].push_back(0);
		for(ll i=1,x;i<=n;i++){
			cin>>x;
			st.push(x*100001*3+i*3+0);
			vlt[0].push_back(x);
			cin>>x;
			st.push(x*100001*3+i*3+1);
			vlt[1].push_back(x);
			cin>>x;
			st.push(x*100001*3+i*3+2);
			vlt[2].push_back(x);
		}
		for(ll p=0,q=0,k=0;!st.empty();){
			p=st.top();
			k=p%3;p/=3;
			q=p%100001;p/=100001;
			st.pop();
			if(vst[q])continue;
			club[k].push_back(q);vst[q]=1;ans+=p;
		}
//		cout<<ans<<" ";
		int cnt=0;
		if((ll)club[0].size()>n/2){
			cnt=club[0].size()-n/2;
			for(int i=0,p;i<(ll)club[0].size();i++){
				p=club[0][i];
				gw.push((vlt[0][p]-vlt[1][p])*100001+p);
				gw.push((vlt[0][p]-vlt[2][p])*100001+p);
			}
		}
		if((ll)club[1].size()>n/2){
			cnt=club[1].size()-n/2;
			for(int i=0,p;i<(ll)club[1].size();i++){
				p=club[1][i];
				gw.push((vlt[1][p]-vlt[2][p])*100001+p);
				gw.push((vlt[1][p]-vlt[0][p])*100001+p);
			}
		}
		if((ll)club[2].size()>n/2){
			cnt=club[2].size()-n/2;
			for(int i=0,p;i<(ll)club[2].size();i++){
				p=club[2][i];
				gw.push((vlt[2][p]-vlt[0][p])*100001+p);
				gw.push((vlt[2][p]-vlt[1][p])*100001+p);
			}
		}
		for(ll p,q,i=0;i<cnt;i++){
			while(!vst[gw.top()%100001])gw.pop();
			p=gw.top()/100001;q=gw.top()%100001;
			vst[q]=0;
			ans-=p;
			gw.pop();
//			cout<<p<<" ";
		}
		cout<<ans<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}
