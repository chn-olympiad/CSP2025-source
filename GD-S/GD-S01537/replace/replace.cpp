#include <bits/stdc++.h>
#define pb push_back 
typedef unsigned long long ull;
using namespace std;
const int N=21e4,L=6e6,B=131,M=1e9+7;
int n,q,mi,ma,ans,l[N],l2[N];
vector<ull> h1[N],h2[N];
ull ht1[N],ht2[N],p[L];
string s1,s2,t1,t2;
int main() {
	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >>n >>q;
	
	for (int i=1;i<=n;i++) {
		cin >>s1 >>s2;
		s1=" "+s1;
		s2=" "+s2;
		l[i]=s1.size();
		h1[i].push_back(0);
		h2[i].push_back(0);
		for (int j=1;j<l[i];j++) {
			h1[i].push_back (ull(h1[i][j-1]*B+s1[j]));
			h2[i].push_back (ull(h2[i][j-1]*B+s2[j]));
		}
		l[i]=h1[i].size()-1;
	}
	p[0]=1;
	for (int i=1;i<=6000000-10;i++) {
		p[i]=p[i-1]*B;
	}
	for (int i=1;i<=q;i++) {
		cin >>t1 >>t2;
		if (t1.size()!=t2.size()) {
			cout <<0 <<"\n";
			continue;
		}
		t1=" "+t1;
		t2=" "+t2;
		mi=1e9;
		ans=ma=0;
		for (int j=1,ll=t1.size();j<=ll;j++) {
			if (t1[j]!=t2[j]) {
				ma=j;
				mi=min(mi,j);
			}
		}
	//	cout <<mi <<" " <<ma <<"\n";
		for (int j=1,ll=t1.size();j<=ll;j++) {
			ht1[j]=ht1[j-1]*B+t1[j];
			ht2[j]=ht2[j-1]*B+t2[j];
		}
		ull len=ma-mi+1,x1=ht1[ma]-ht1[mi-1]*p[len],x2=ht2[ma]-ht2[mi-1]*p[len];
		for (int j=1;j<=n;j++) {
			for (int k=len;k<=l[j];k++) {
				ull p1=h1[j][k]-h1[j][k-len]*p[len],p2=h2[j][k]-h2[j][k-len]*p[len];
				
				if (p1==x1 && p2==x2) {
					if (h1[j][l[j]]==  ht1[mi-k+len+l[j]-1]-ht1[mi-k+len-1]*p[l[j]]   && h2[j][l[j]]==ht2[mi-k+len+l[j]-1]-ht2[mi-k+len-1]*p[l[j]]) {
						ans++;
					}
				}
			}
		}
		cout <<ans <<"\n";
	}
	return 0;
}

