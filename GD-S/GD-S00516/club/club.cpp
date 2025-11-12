#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int MAXN=1e5+5;
int n;ll ans=0;
vector<ll> d[3];
void solve(){
	cin>>n;ans=0;
	for(int i=0;i<3;i++) d[i].clear();
	for(int i=1;i<=n;i++){
		ll a,b,c;cin>>a>>b>>c;
		ans+=max({a,b,c});
		if(a==max({a,b,c})) d[0].push_back(a-max(b,c));
		else if(b==max({a,b,c})) d[1].push_back(b-max(a,c));
		else d[2].push_back(c-max(a,b));
	}
	for(int i=0;i<3;i++) if((int)d[i].size()>n/2){
		sort(d[i].begin(),d[i].end());
		for(int j=0;j<(int)d[i].size()-n/2;j++) ans-=d[i][j];
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int T;cin>>T;
	while(T--) solve(); 
}
/*
Minasan, hajimemashite, Otomachi Una desu~~, a grade 12 OIer, maybe you know me.
This maybe my last year in CSP (hopefully i will take part in it some next year, 
when I study PKU).
So i will post this as my <CSPS2025 YOUJI>


this is what happen before the contest:
Yesturday I played game <deleted>, and passed the Shirasaki rount.
Wake up at about 9:00 am. Watch Weibo for about 1h and go sleep again.
After wake up again, it is 11:50 while the school bus go at 12:20.
I brought M.C. online. But when I got there, there was a lot of people. I cant wait!!!
so I brought one bottle water and one bread at Family Market at 12:15
then i ran to school. I am on time.


this is what happen during the contest:
solved A at first about 10 minute.
Problem B is a classic MST and dfs problem. After I read the problem before read Constraints, I 
realize this problem is hard to do poly(nk), so k must by very small ~~ that is
solved B at about 25 minute
Problem C is about string. before CSP, I talk to my friend that I guess there will at least two
problem about ds. But obviously, Im wrong :( this problem is a easy string+ds problem, 
to solve this, you can just use trie and 2-d counting by BIT.
solved C at about 1h
Problem D is counting!!! actually yesturday Starsilk (Champion of WF 2025) said he wish there will
be 4 counting problems. Now, the counting in at Problem D. btw, Im not good at counting :(
But furtunaly I solved it because this is a PIE Problem. I am a little known PIE tricks. 
(but why you didnt solve D2T2 you db)
solve D and AK CSPS2025 at about 16:30, only 2 hours.
CSP should hurry up!!!
Addtionly, Problem D can do every m from 0 ~ n but the problem only ask us to calculate one. HEYIWEI?

17:00 write this youji
17:24 wrote a checker for Problem C,D

Otomachi Una, 2025/11/1 at GDF with love
祝你漫长的人生路上，永远有幸福的魔法相伴。 
*/
