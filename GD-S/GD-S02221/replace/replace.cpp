#include <bits/stdc++.h>
#define fir first
#define sec second
using namespace std;
typedef unsigned long long ull;
typedef pair<ull,ull> puu;
const int N=2005,M=4005;
const ull p1=23333,p2=2333333333333;
int n,q;
struct Node{
	puu x;
	int len;
};
map<puu,Node> v;
puu a[N],b[N];
ull fac1[M],fac2[M];
struct Node2{
	int x1,pos1,y1;
	int x2,pos2,y2;
}A[200005];
map<int,vector<Node2> >v2;
puu gethash(string s) {
	int len=s.size();
	ull ans1=0,ans2=0;
	for (int i=0;i<len;i++) {
		ans1=ans1*p1+(ull)s[i];
		ans2=ans2*p2+(ull)s[i];
	}
	return (puu){ans1,ans2};
}
puu querya(int l,int r) {
	return (puu){a[r].fir-a[l-1].fir*fac1[r-l+1],a[r].sec-a[l-1].sec*fac2[r-l+1]};
}
puu queryb(int l,int r) {
	return (puu){b[r].fir-b[l-1].fir*fac1[r-l+1],b[r].sec-b[l-1].sec*fac2[r-l+1]};
}
void solve1(string s1,string s2) {
	int len1=s1.size(),len2=s2.size();
	for (int i=0;i<len1;i++) {
		a[i+1].fir=a[i].fir*p1+s1[i];
		a[i+1].sec=a[i].sec*p2+s1[i];
	}
	for (int i=0;i<len2;i++) {
		b[i+1].fir=b[i].fir*p1+s2[i];
		b[i+1].sec=b[i].sec*p2+s2[i];
	}
	int ans=0;
	for (int len=1;len<=2000;len++) {
		for (int i=1;i+len-1<=len1;i++) {
			int l=i,r=i+len-1;
			if (v.find(querya(l,r))==v.end()) {
				continue;
			}
			ull ti1=v[querya(l,r)].x.fir;
			ull ti2=v[querya(l,r)].x.sec;
			int tlen=v[querya(l,r)].len;
			ull t1=a[l-1].fir*fac1[len1-l+1]+ti1*fac1[len1-r]+querya(r+1,len1).fir;
			ull t2=a[l-1].sec*fac2[len1-l+1]+ti2*fac2[len1-r]+querya(r+1,len1).sec;
			if ((puu){t1,t2}==b[len2]) {
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}
int check(string s) {
	int cnt=0;
	for (int i=0;i<s.size();i++) {
		if (s[i]!='a'&&s[i]!='b') {
			return 0;
		}
		if (s[i]=='b') {
			cnt++;
			if (cnt>=2) {
				return 0;
			}
		}
	}
	return 1;
}
void solve2(string s1,string s2) {
	int spos1=0,spos2=0;
	int len1=s1.size(),len2=s2.size();
	for (int i=0;i<len1;i++) {
		if (s1[i]=='b') {
			spos1=i;
			break;
		}
	}
	for (int i=0;i<len2;i++) {
		if (s2[i]=='b') {
			spos2=i;
			break;
		}
	}
	vector<Node2> ve=v2[spos1-spos2];
	int ans=0;
	for (int i=0;i<ve.size();i++) {
		if (ve[i].pos1>spos1||ve[i].y1>len1-1-spos1) continue;
		if (len1-ve[i].x1-ve[i].y1+ve[i].x2+ve[i].y2!=len2) continue;
		ans++;
	}
	printf("%d\n",ans);
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d %d",&n,&q);
	int flag=1;
	for (int i=1;i<=n;i++) {
		string s1,s2;
		cin>>s1>>s2;
		v[gethash(s1)]=(Node){gethash(s2),(int)s2.size()};
		if (flag==0) continue;
		if (flag==1&&check(s1)==0) {
			flag=0;
			continue;
		}
		if (flag==1&&check(s2)==0) {
			flag=0;
			continue;
		}
		for (int j=0;j<s1.size();j++) {
			if (s1[j]=='b') {
				A[i].pos1=j;
				A[i].x1=j;
				A[i].y1=s1.size()-1-j;
				break;
			}
		}
		for (int j=0;j<s2.size();j++) {
			if (s2[j]=='b') {
				A[i].pos2=j;
				A[i].x2=j;
				A[i].y2=s2.size()-1-j;
				break;
			}
		}
		v2[A[i].pos1-A[i].pos2].push_back(A[i]);
	}
	fac1[0]=fac2[0]=1;
	for (int i=1;i<M;i++) {
		fac1[i]=fac1[i-1]*p1;
		fac2[i]=fac2[i-1]*p2;
	}
	while (q--) {
		string s1,s2;
		cin>>s1>>s2;
		if (flag==0||check(s1)==0||check(s2)==0) {
			solve1(s1,s2);
		}else {
			solve2(s1,s2);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

