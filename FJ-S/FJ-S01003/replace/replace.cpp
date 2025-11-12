#include<bits/stdc++.h>
#include<deque>
#define int long long
#define ll long long
using namespace std;

struct STR{
	deque<char> s1,s2;
	ll l;
}s[200005];

ll n,t;
string t1,t2;
deque<char> a1,a2;

bool cmp(STR aa,STR bb){
	return aa.l<bb.l;
}

ll erfen(ll cd){
	ll lt=1,rt=n;
	while(lt<rt){
		ll mid=lt+(rt-lt)/2;
		if(cd<=s[mid].l) rt=mid;
		else lt=mid+1;
	}
	return lt;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;++i){
		string ss1="",ss2="";
		cin>>ss1>>ss2;
		s[i].l=ss1.size();
		for(int j=0;j<s[i].l;j++){
			s[i].s1.push_back(ss1[j]);
			s[i].s2.push_back(ss2[j]);
		}
	}
	sort(s+1,s+n+1,cmp);
	for(int i=1;i<=t;++i){
		ll ans=0;a1.clear();a2.clear();
		cin>>t1>>t2;
		int cd=t1.size()-1,lt=0,rt=cd;
		//cout<<"cd="<<cd<<"\n";
		if(cd+1!=t2.size()){
			cout<<0<<"\n";
			continue;
		}
		while(t1[lt]==t2[lt]){
			++lt;
		}
		while(t1[rt]==t2[rt]){
			--rt;
		}
		for(int j=lt;j<=rt;++j){
			a1.push_back(t1[j]);
			a2.push_back(t2[j]);
		}
		ll id=erfen(rt-lt+1);
		ll llt=lt,rrt=rt;bool fx=0;
		//cout<<"lt="<<lt<<" rt="<<rt<<"\n"; 
		for(int j=id;j<=n;++j){
			if(s[j].l>cd+1) break;
			//cout<<"³¤¶È="<<rrt-llt+1<<" "<<s[j].l<<"\n";
			while(rrt-llt+1<s[j].l){
				if(!fx){
					if(0<llt){
						--llt;
						a1.push_front(t1[llt]);
						a2.push_front(t2[llt]);
					}else{
						++rrt;
						a1.push_back(t1[rrt]);
						a2.push_back(t2[rrt]);
					}
				}else{
					if(rrt<cd){
						++rrt;
						a1.push_back(t1[rrt]);
						a2.push_back(t2[rrt]);
					}
					else{
						--llt;
						a1.push_front(t1[llt]);
						a2.push_front(t2[llt]);
					}
				}
			}
			////////////////////
			while(1){
				//cout<<"j="<<j<<" "<<llt<<" "<<rrt<<"\n";
				if(a1==s[j].s1&&a2==s[j].s2){
					++ans;
					break;
				}
				if(!fx){
					if(0<llt&&rt<rrt){
						--rrt;
						a1.pop_back();
						a2.pop_back();
						--llt;
						a1.push_front(t1[llt]);
						a2.push_front(t2[llt]);
					}else{
						break;
					}
				}else{
					if(llt<lt&&rrt<cd){
						++llt;
						a1.pop_front();
						a2.pop_front();
						++rrt;
						a1.push_back(t1[rrt]);
						a2.push_back(t2[rrt]);
					}else{
						break;
					}
				}
			}
			fx=!fx;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/
