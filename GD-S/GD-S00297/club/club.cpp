#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
typedef priority_queue<piii,vector<piii>,greater<piii>> pqppp;
struct person{
	int a,b,c;
};
person p[N];
bool cmp(person a, person b){
	if(a.a != b.a) return a.a > b.a;
	else if(a.b != b.b) return a.b > b.b;
	else return a.c > b.c;
}
int amax;
void addtoaa(int i,pqppp &aaa,pqppp &bbb,pqppp & ccc);
void addtobb(int i,pqppp &aaa,pqppp &bbb,pqppp & ccc);
void addtocc(int i,pqppp &aaa,pqppp &bbb,pqppp & ccc);

void addtoaa(int i,pqppp &aaa,pqppp &bbb,pqppp & ccc){
	if(aaa.size() < amax) aaa.push({p[i].a,{p[i].b,p[i].c}});
	else{
		if(aaa.top().first > p[i].a){
			addtobb(i,aaa,bbb,ccc);
		}
		else{
			if(p[i].b > p[i].c){
				bbb.push({aaa.top().second.first,{aaa.top().first,aaa.top().second.second}});
			}
			else{
				ccc.push({aaa.top().second.first,{aaa.top().first,aaa.top().second.first}});
			}
			aaa.pop();
			aaa.push({p[i].a,{p[i].b,p[i].c}});
		}
	}
}

void addtobb(int i,pqppp &aaa,pqppp &bbb,pqppp & ccc){
	if(bbb.size() < amax) bbb.push({p[i].b,{p[i].a,p[i].c}});
	else{
		if(bbb.top().first > p[i].b){
			addtocc(i,aaa,bbb,ccc);
		}
		else{
			if(p[i].a > p[i].c){
				aaa.push({bbb.top().second.first,{bbb.top().first,bbb.top().second.second}});
			}
			else{
				ccc.push({bbb.top().second.second,{bbb.top().second.first,bbb.top().first}});
			}
			bbb.pop();
			bbb.push({p[i].b,{p[i].a,p[i].c}});
		}
	}
}

void addtocc(int i,pqppp &aaa,pqppp &bbb,pqppp & ccc){
	if(ccc.size() < amax) ccc.push({p[i].c,{p[i].a,p[i].b}});
	else{
		if(ccc.top().first > p[i].c){
			addtoaa(i,aaa,bbb,ccc);
		}
		else{
			if(p[i].a > p[i].b){
				aaa.push({ccc.top().second.first,{ccc.top().second.second,ccc.top().first}});
			}
			else{
				bbb.push({ccc.top().second.second,{ccc.top().second.first,ccc.top().first}});
			}
			ccc.pop();
			ccc.push({p[i].c,{p[i].a,p[i].b}});
		}
	}
}
void solve(){
	int n;
	cin >> n;
	bool flag = true,flag2 = true;
	for(int i = 1 ; i <= n ; i++ ){
		cin >> p[i].a >> p[i].b >> p[i].c;
		if(p[i].b != 0 || p[i].c != 0) flag = false;
		if(p[i].c != 0) flag2 = false;
	}
	amax = n / 2;
	if(flag){
		ll ans = 0;
		sort(p + 1 , p + n + 1 , cmp);
		for(int i = 1 ; i <= amax ; i++ ) ans += p[i].a;
		cout << ans << endl;
		return;
	}
	if(flag2){
		priority_queue<pii,vector<pii>,greater<pii>>aa,bb;
		for(int i = 1 ; i <= n ; i++ ){
			if(p[i].a > p[i].b){
				if(aa.size() < amax) aa.push({p[i].a,p[i].b});
				else{
					if(aa.top().first > p[i].a) bb.push({p[i].b,p[i].a});
					else{
						bb.push({aa.top().second,aa.top().first});
						aa.pop();
						aa.push({p[i].a,p[i].b});
					}
				}
			}
			else{
				if(bb.size() < amax) bb.push({p[i].b,p[i].a});
				else{
					if(bb.top().first > p[i].b) aa.push({p[i].a,p[i].b});
					else{
						aa.push({bb.top().second,bb.top().first});
						bb.pop();
						bb.push({p[i].b,p[i].a});
					}
				}
			}
		}
		ll ans = 0;
		while(aa.size()){
			ans += aa.top().first;
			aa.pop();
		}
		while(bb.size()){
			ans += bb.top().first;
			bb.pop();
		}
		cout << ans << endl;
		return;
	}
	pqppp aa,bb,cc;
	for(int i = 1 ; i <= n ; i++ ){
		if(p[i].a > p[i].b && p[i].a > p[i].c){
			addtoaa(i,aa,bb,cc);
		}
		else if(p[i].b > p[i].c && p[i].b > p[i].a){
			addtobb(i,aa,bb,cc);
		}
		else{
			addtocc(i,aa,bb,cc);
		}
	}
	ll ans = 0;
	while(aa.size()){
		ans += aa.top().first;
		aa.pop();
	} 
	while(bb.size()){
		ans += bb.top().first;
		bb.pop();
	}
	cout << ans << endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int t;
	cin >> t;
	
	while(t--) solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
