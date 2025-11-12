#include <bits/stdc++.h>
using namespace std;
#define in(s) freopen(s,"r",stdin)
#define out(s) freopen(s,"w",stdout)

namespace FastIO{
	const int size = 1<<20;
	char rbuf[size],*p1=rbuf,*p2=rbuf,c;
	int f;
	char mgetchar(){
		if (p1 == p2){
			p2 = (p1=rbuf)+fread(rbuf,1,size,stdin);
		}
		return (p1 == p2 ? EOF : *p1++);
	}
	void mread(int &x){
		x = 0;
		f = 1;
		c = mgetchar();
		while (c < '0' || '9' < c){
			if (c == '-')	f = -f;
			c = mgetchar();
		}
		while ('0' <= c && c <= '9'){
			x *= 10;
			x += c-'0';
			c = mgetchar();
		}
		x *= f;
	}
	void mreadstr(string &s){
		s = "";
		c = mgetchar();
		while (c < 'a' || 'z' < c){
			c = mgetchar();
		}
		while('a' <= c && c <= 'z'){
			s += c;
			c = mgetchar();
		}
	}
}

int n,q,las,ans;
string arr[200005][2];
string t1,t2,tep;
map<string,map<string,int> > mp;

int main(){
	in("replace.in");
	out("replace.out");
//	scanf("%d%d",&n,&q);
	FastIO::mread(n);
	FastIO::mread(q);
	for(int i=1;i<=n;i++){
//		cin >> arr[i][0] >> arr[i][1];
		FastIO::mreadstr(arr[i][0]);
		FastIO::mreadstr(arr[i][1]);
	}
	while (q--){
		FastIO::mreadstr(t1);
		FastIO::mreadstr(t2);
		ans = 0;
		for(int i=1;i<=n;i++){
			las = 0;
			while ((int)t1.find(arr[i][0],las) != -1){
				tep = t1.substr(0,t1.find(arr[i][0],las))+arr[i][1]+t1.substr(t1.find(arr[i][0],las)+arr[i][0].size());
				if (tep == t2){
					ans++;
				}
				las = t1.find(arr[i][0],las)+1;
			}
		}
		printf("%d\n",ans);
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
