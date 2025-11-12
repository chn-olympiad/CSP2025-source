#include<bits/stdc++.h>
using namespace std;
struct node{
	int a, b, c, num;
};
int n;
const int ma = 1e6;
node k[ma];
struct nl{
	char one, two, three;
};
nl l[ma];
node k1[ma];
int cnta = 0, cntb = 0, cntc = 0;
vector<node>aa, bb, cc;
bool cmp(node x, node y){
	if(l[x.num].two == 'b' && l[y.num].two == 'b'){
		return x.a - x.b < y.a - y.b;
	}else if(l[x.num].two == 'b' && l[y.num].two == 'c'){
		return x.a - x.b < y.a - y.c;
	}else if(l[x.num].two == 'c' && l[y.num].two == 'b'){
		return x.a - x.c < y.a - y.b;
	}else if(l[x.num].two == 'c' && l[y.num].two == 'c'){
		return x.a - x.c < y.a - y.c;
	}
}
int ansa = 0, ansb = 0, ansc = 0;
void ccfa(){
	int kkk = cnta - n / 2;
	sort(aa.begin(), aa.end(), cmp);
	for(int i = 0; i < kkk; i++){
		ansa -= aa[i].a;
		if(l[aa[i].num].two == 'b'){
			cntb ++;
			ansb += aa[i].b;
			l[aa[i].num].one = 'b';
			l[aa[i].num].two ='c';
			bb.push_back(aa[i]);
		}else{
			cntc++;
			ansc += aa[i].c;
			l[aa[i].num].one = 'c';
			l[aa[i].num].two ='b';
			cc.push_back(aa[i]);
		}
	}
}
bool cmpb(node x, node y){
	if(l[x.num].two == 'a' && l[y.num].two == 'a'){
		return x.b - x.a < y.b - y.a;
	}else if(l[x.num].two == 'a' && l[y.num].two == 'c'){
		return x.b - x.a < y.b - y.c;
	}else if(l[x.num].two == 'c' && l[y.num].two == 'a'){
		return x.b - x.c < y.b - y.a;
	}else if(l[x.num].two == 'c' && l[y.num].two == 'c'){
		return x.b - x.c < y.b - y.c;
	}
}
void ccfb(){
	int kkk = cntb - n / 2;
	sort(bb.begin(), bb.end(), cmpb);
	for(int i = 0; i < kkk; i++){
		ansb -= bb[i].b;
		if(l[bb[i].num].two == 'a'){
			ansa += bb[i].a;
			cnta++;
			l[bb[i].num].one = 'a';
			l[bb[i].num].two ='c';
			aa.push_back(bb[i]);
		}else{
			cntc++;
			ansc += bb[i].c;
			l[bb[i].num].one = 'c';
			l[bb[i].num].two ='a';
			cc.push_back(bb[i]);
		}
	}
}
bool cmpc(node x, node y){
	if(l[x.num].two == 'a' && l[y.num].two == 'a'){
		return x.c - x.a < y.c - y.a;
	}else if(l[x.num].two == 'a' && l[y.num].two == 'b'){
		return x.c - x.a < y.c - y.b;
	}else if(l[x.num].two == 'b' && l[y.num].two == 'a'){
		return x.c - x.b < y.c - y.a;
	}else if(l[x.num].two == 'b' && l[y.num].two == 'b'){
		return x.c - x.b < y.c - y.b;
	}
}
void ccfc(){
	int kkk = cntc - n / 2;
	sort(cc.begin(), cc.end(), cmpc);
	for(int i = 0; i < kkk; i++){
		ansc -= cc[i].c;
		if(l[bb[i].num].two == 'a'){
			ansa += cc[i].a;
			cnta ++;
			l[cc[i].num].one = 'a';
			l[cc[i].num].two ='b';
			aa.push_back(cc[i]);
		}else{
			cntb++;
			ansb += cc[i].b;
			l[cc[i].num].one = 'b';
			l[cc[i].num].two ='a';
			bb.push_back(cc[i]);
		}
	}
}
int main(){
	freopen("club.out", "r", stdin);
	freopen("club.in", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		cnta = 0, cntb = 0, cntc = 0;
		ansa = 0, ansb = 0, ansc = 0;
		aa.clear(), bb.clear(), cc.clear();
		for(int i = 1; i <= n; i++){
			cin >> k[i].a >> k[i].b >> k[i].c;
			k[i].num = i;
		}
		for(int i = 1; i <= n; i++){
			k1[i].a = max(k[i].a, max(k[i].b, k[i].c));
			k1[i].c = min(k[i].a, min(k[i].b, k[i].c));
			k1[i].b = k[i].a + k[i].b + k[i].c - k1[i].a - k1[i].c; 
		}
		for(int i = 1; i <= n; i++){
			if(k[i].a >= k[i].b && k[i].a >= k[i].b){
				cnta++;
				aa.push_back(k[i]);
				l[i].one = 'a';
				if(k[i].b >= k[i].c){
					l[i].two = 'b';
					l[i].three = 'c';	
				}else{
					l[i].three = 'b';
					l[i].two = 'c';
				}
				ansa += k[i].a;
			}else if(k[i].b >= k[i].c && k[i].b >= k[i].c){
				cntb++;
				l[i].one = 'b';
				bb.push_back(k[i]);
				if(k[i].a >= k[i].c){
					l[i].two = 'a';
					l[i].three = 'c';
				}else{
					l[i].two = 'c';
					l[i].three = 'a';
				}
				ansb += k[i].b;
			}else if(k[i].c >= k[i].b && k[i].c >= k[i].a){
				cntc++;
				l[i].one = 'c';
				cc.push_back(k[i]);
				if(k[i].a >= k[i].b){
					l[i].two = 'a';
					l[i].three = 'b';
				}else{
					l[i].two = 'b';
					l[i].three = 'a';
				}
				ansc += k[i].c;
			}
		}
		if(cnta > n / 2){
			ccfa();
		}
		if(cntb > n / 2){
			ccfb();
		}
		if(cntc > n / 2){
			ccfc();
		}
		cout << ansa + ansb + ansc << endl;
	}
	return 0;
} 
