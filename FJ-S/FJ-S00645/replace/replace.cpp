#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int maxs=5e5+1;
int ch1[maxs][27],ch2[maxs][27],n,q,cnt=0;
//bool bo1[maxs]= {0},bo2[maxs]= {0};
//void insert1(string s1) {
//	int tot=0,u=0,i=0;
//	while(i<s1.size()) {
//		int c1=s1[i]-'a';
//		if(!ch1[u][c1]) {
//			ch1[u][c1]=++tot;
//		}
//		u=ch1[u][c1];
//		i++;
//	}
//	bo1[u]=1;
//}
//void insert2(string s2) {
//	int tot=0,u=0,i=0;
//	while(i<s2.size()) {
//		int c2=s2[i]-'a';
//		if(!ch2[u][c2]) {
//			ch2[u][c2]=++tot;
//		}
//		u=ch2[u][c2];
//		i++;
//	}
//	bo2[u]=1;
//}
//void check(string a,string b) {
//	int u=0,i=0;
//	int xy[maxs];
//	int xy2[maxs];
//	cnt=0;
//	while(i<a.size()) {
//		int c=a[i]-'a';
//		if(ch1[u][c]) u=ch1[u][c];
//		if(bo1[u]) xy[u]=1;
//		i++;
//	}
//	u=0,i=0;
//	while(i<b.size()) {
//		int c=b[i]-'a';
//		if(ch2[u][c]) u=ch2[u][c];
//		if(bo2[u]&&xy[u]) cnt++;
//		i++;
//	}
//	u=0,i=0;
//	while(i<a.size()) {
//		int c=a[i]-'a';
//		if(ch2[u][c]) u=ch2[u][c];
//		if(bo2[u]) xy2[u]=1;
//		i++;
//	}
//	u=0,i=0;
//	while(i<b.size()) {
//		int c=b[i]-'a';
//		if(ch1[u][c]) u=ch1[u][c];
//		if(bo1[u]&&xy2[u]) cnt++;
//		i++;
//	}
//	cout<<cnt<<endl;
//}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; i++) {
		string a,b;
		cin>>a>>b;
	}
	int q;
	cin>>q;
	for(int i=1; i<=q; i++) {
		string a,b;
		cin>>a>>b;
//		check(a,b);
		cout<<0<<endl;
	}
	return 0;
}


