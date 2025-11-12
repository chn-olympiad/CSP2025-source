#include<bits/stdc++.h>
using namespace std;
int n,k,r=-1,cnt,a[100010], s[100010];
struct Pair{
	int l,r;
};
bool cmp(Pair a, Pair b){
	return a.r<b.r;
}
vector<Pair> p;
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> k;
	for(int i=1; i<=n; i++)
		cin >> a[i];
	s[0]=0;
	s[1]=a[1];
	for(int i=2; i<=n; i++)
		s[i]=a[i]^s[i-1];
	for(int i=1; i<=n; i++)
		for(int j=i; j<=n; j++){
			int o=s[j]^s[i-1];
			if(o==k){
				Pair t;
				t.l=i, t.r=j;
				p.push_back(t);
			}
		}
	sort(p.begin(), p.end(), cmp);
	for(Pair c : p)
		if(c.l>r)
			cnt++,r=c.r;
	cout << cnt;			
	return 0;
}
