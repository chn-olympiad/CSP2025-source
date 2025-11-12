#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pint pair<int,int>
#define _rep(i,a,b) for(int i=(a);i<=(b);++i)
#define fst first
#define snd second
#define FRR(file) freopen(file,"r",stdin)
#define FRW(file) freopen(file,"w",stdout)
#define pb push_back

int in(){
	char a = getchar();
	int k = 0, kk = 1;
	while(!isdigit(a)){
		if(a == '-') kk = -1;
		a = getchar();
	}
	while(isdigit(a)){
		k = k * 10 + a - '0', a = getchar();
	}
	return k*kk;
}
void out(int a){
	if(a < 0) putchar('-'),a=-a;
	if(a > 9) out(a/10);
	putchar('0'+a%10);
}
const int N = 1e5 + 5;

int n;
struct node{
	int a,b,c,d;
}s[N];
bool cmp(int a,int b){
	return a > b;
}
int mid(int a,int b,int c){
	vector <int> s; s.pb(a); s.pb(b), s.pb(c);
	sort(s.begin(),s.end());
	return s[1];
}
void work(){
	int n = in();
	vector <int> ss[4];
	int ans = 0;
	_rep(i,1,n){
		s[i].a=in(),s[i].b=in(),s[i].c=in();
		int maxn = max(max(s[i].a,s[i].b),s[i].c);
		s[i].d = mid(s[i].a,s[i].b,s[i].c);
		ans += maxn;
		if(s[i].a == maxn) ss[1].pb(i);
		else if(s[i].b == maxn) ss[2].pb(i);
		else if(s[i].c == maxn) ss[3].pb(i);
	}
//	cout << "1 : " << ss[1].size() << " 2 : " << ss[2].size() << " 3 : " << ss[3].size() << " ans = " << ans << endl; 
//	cout << "-----------\n";
//	for(int i=1;i<=n;i++){
//		cout << i << " " << s[i].d << endl;
//	}
//	cout << "-----------\n";
	vector <int> tmp;
	if((int)ss[1].size() > n / 2){
		for(int i:ss[1]){
			tmp.pb(s[i].d-s[i].a);
		}
		sort(tmp.begin(),tmp.end(),cmp);
		int len = ss[1].size();
		for(int i=0;i<len-n/2;++i){
//			cout << "!!!!" << tmp[i] << endl;
			ans += tmp[i];
		}
	}else if((int)ss[2].size() > n / 2){
		for(int i:ss[2]){
			tmp.pb(s[i].d-s[i].b);
		}
		sort(tmp.begin(),tmp.end(),cmp);
		int len = ss[2].size();
		for(int i=0;i<len-n/2;++i){
			ans += tmp[i];
		}
	}else if((int)ss[3].size() > n / 2){
		for(int i:ss[3]){
			tmp.pb(s[i].d-s[i].c);
		}
		sort(tmp.begin(),tmp.end(),cmp);
		int len = ss[3].size();
		for(int i=0;i<len-n/2;++i){
			ans += tmp[i];
		}
	}
	out(ans), putchar('\n');
}
signed main(){
	FRR("club.in");
	FRW("club.out");
//	FRR("in.txt");
//	FRW("mine.txt");
	int T = in();
	while(T--){
		work();
	}	
	
	return 0;
}
