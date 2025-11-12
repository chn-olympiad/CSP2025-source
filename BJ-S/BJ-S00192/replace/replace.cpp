#include <iostream>
#include <cstdio>
#include <map>
#define int long long
#define Mod1 1000000007
#define Mod2 998244353
using namespace std;
int n,q;
string s1[1010],s2[1010];
bool can[1010];
struct Node{
	int aa,bb;
	bool operator <(const Node &__) const {return aa<__.aa||(aa==__.aa&&bb<__.bb);}
	bool operator ==(const Node &__) const {return aa==__.aa&&bb==__.bb;}
};
struct PP{
	Node _1,_2;
	bool operator <(const PP &__) const {return _1<__._1||(_1==__._1&&_2<__._2);}
};
map<PP,int> mp;
struct Node{
	int l,r,c,id;
}p[400010];
int tot=0;
void fun(void) {
	for (int i=1;i<=q;i++) {
		string ss1,ss2;
		cout << 0 << endl;
	}
}
signed main(void) {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> q;
	if (n>100) {
		fun();
		return 0;
	}
	for (int i=1;i<=n;i++) {
		int p1=0,p2=0;
		cin >> s1[i] >> s2[i];
		for (int j=0;j<(int)s1[i].size();j++) {
			p1=(p1*131+s1[i][j])%Mod1;
			p2=(p2*129+s1[i][j])%Mod2;
		}
		Node x=Node{p1,p2};
		p1=p2=0;
		for (int j=0;j<(int)s2[i].size();j++) {
			p1=(p1*131+s2[i][j])%Mod1;
			p2=(p2*129+s2[i][j])%Mod2;
		}
//		cout << x.aa << " " << p1 << endl;
		mp[PP{x,Node{p1,p2}}]++;
	}
	for (;q--;) {
		string ss1,ss2;
		cin >> ss1 >> ss2;
		int l=ss1.size()-1;
		int ans=0;
		for (int i=0;i<=l;i++) {
			int p1=0,p2=0,pp1=0,pp2=0;
			bool vv=1;
			for (int j=0;j<i;j++) {
				if (ss1[j]!=ss2[j]) vv=0;
			}
			if (vv==0) break;
			can[l+1]=1;
			for (int j=l;j>=i;j--) {
				if (ss1[j]!=ss2[j]) {
					can[j]=0;
				} else can[j]=1;
				if (j!=l) can[j]^=can[j+1];
//				cout << j << " " << can[j] << endl;
			}
			for (int j=i;j<=l;j++) {
				p1=(p1*131+ss1[j])%Mod1;
				p2=(p2*129+ss1[j])%Mod2;
				Node x=Node{p1,p2};
				pp1=(pp1*131+ss2[j])%Mod1;
				pp2=(pp2*129+ss2[j])%Mod2;
//				cout << x.aa << " " << pp1 << endl;
				if (mp.count(PP{x,Node{pp1,pp2}})&&can[j+1]) ans+=mp[PP{x,Node{pp1,pp2}}];//,cout << i << " " << j << endl;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
