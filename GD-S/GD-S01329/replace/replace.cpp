#include<bits/stdc++.h>
#define ll long long
#define e_b emplace_back
#define ios ios::sync_with_stdio(0),cin.tie(0)
#define pii pair<int,int>
#define fir frist
#define sec second
using namespace std;
const int N=2e5+5;
int n,q,ans;
int l[N],r[N];
vector<pii>p[2][N];
string s1[N],s2[N];
void solve1(){
	for(int i=1;i<=n;i++){
		int a,b;
		string s;
		cin>>s;
		int len=s.size();
		for(int j=0;j<s.size();j++)if(s[j]=='b'){a=j;break;}
		cin>>s;
		for(int j=0;j<s.size();j++)if(s[j]=='b'){b=j;break;}
		if(a==b)p[0][0].e_b(pii{a,len-a});
		else if(a>b)p[0][a-b].e_b(pii{b,len-a});	
		else p[1][b-a].e_b(pii{a,len-b});
	}
	for(int i=0;i<2;i++)for(int j=1;j<=n;j++)sort(p[i][j].begin(),p[i][j].end());
	while(q--){
		string s,t;
		cin>>s>>t;
		int a,b,len=s.size();
		for(int j=0;j<s.size();j++)if(s[j]=='b'){a=j;break;}
		for(int j=0;j<t.size();j++)if(t[j]=='b'){b=j;break;}
		if(a>=b){
			auto k=lower_bound(p[0][a-b].begin(),p[0][a-b].end(),pii{b,len-a});
			ans=(k-p[0][a-b].begin());
			cout<<max(ans,0)<<'\n';
		}
		else{
			auto k=lower_bound(p[1][b-a].begin(),p[1][b-a].end(),pii{a,len-b});
			ans=(k-p[1][b-a].begin());
			cout<<max(ans,0)<<'\n';
		}
	}
}
void solve2(){
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i];
	while(q--){
		string s,t;
		cin>>s>>t;
		for(int i=1;i<=n;i++){
			int len=s1[i].size();
			for(int j=0;j<s.size()-len+1;j++){
				bool f=0;
				for(int k=j;k<=j+len-1;k++)if(s[j+k]!=s1[i][k])f=1;
				for(int k=j;k<=j+len-1;k++)if(t[j+k]!=s2[i][k])f=1;
				if(!f)ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios;cin>>n>>q;
	if(n<=1000)solve2();
	else solve1(); 
	return 0;
}

