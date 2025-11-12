#include<iostream>
using namespace std;
const int N = 200001;

string ins;
int n,q,ans;
struct Str{int l,r;}s[N],s1[N],t[N],t1[N];

bool check(int x,int y){
	return (s[y].l <= t[x].l && s[y].r <= t[x].r);
}

void tn(string s,Str &a){
	int n = s.size();
	for(int i = 0;i < n;++i)
		if(s[i] == 'b'){
			a.l = i;
			a.r = n-i-1;
			return;
		}
	return;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;++i){
		cin >> ins;tn(ins,s[i]);
		cin >> ins;tn(ins,s1[i]);
	}
	for(int i = 1;i <= q;++i){
		cin >> ins;tn(ins,t[i]);
		cin >> ins;tn(ins,t1[i]);
		int opt = t[i].l - t1[i].l;
		for(int j = 1;j <= n;++j)
			ans += (s[j].l-s1[j].l == opt && check(i,j));
		cout << ans << '\n';ans = 0;
	}
	return 0;
}
