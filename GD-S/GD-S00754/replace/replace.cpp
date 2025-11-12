#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#define ll long long
#define db long double
#define endl '\n'
using namespace std;
const int MAXN=2e5+5,MAXM=5e6+5,MOD=0;
const long long INF=(1ll<<62);
ll T=1,n,Q;
struct STRG{
	string s1,s2;
	ll len;
} a[MAXN];
bool CHK=0;
ll to[MAXN],nxt[MAXN],frt[MAXN];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	while (T--){
		cin>>n>>Q;
		for (int i=1;i<=n;i++){
			cin>>a[i].s1>>a[i].s2;
			a[i].len=a[i].s1.length();
			bool chk=0;
			ll cnt1=0,cnt2=0,plc1,plc2;
			for (int j=0;j<a[i].len;j++){
				if (a[i].s1[j]!='a' && a[i].s1[j]!='b') chk=1;
				if (a[i].s2[j]!='a' && a[i].s2[j]!='b') chk=1;
				if (a[i].s1[j]=='b') ++cnt1,plc1=j;
				if (a[i].s2[j]=='b') ++cnt2,plc2=j;
			}
			if (!chk && cnt1==1 && cnt2==1){
				to[i]=plc2-plc1;
				nxt[i]=a[i].len-1-plc1;
				frt[i]=plc1+1;
				continue;
			}
			else CHK=1;
		}
		while (Q--){
			string s1,s2;
			ll m,st,ed;
			cin>>s1>>s2;
			ll cnt1=0,cnt2=0;
			ll res=0;
			if (s1.length()!=s2.length()){
				cout<<0<<endl;
				continue;
			}
			m=s1.length();
			s1=" "+s1,s2=" "+s2;
			if (!CHK){
				bool chk=0;
				ll plc1=0,plc2=0;
				for (int j=1;j<=m;j++){
					if (s1[j]!='a' && s1[j]!='b') chk=1;
					if (s2[j]!='a' && s2[j]!='b') chk=1;
					if (s1[j]=='b') ++cnt1,plc1=j;
					if (s2[j]=='b') ++cnt2,plc2=j;
				}
				if (!chk && cnt1==1 && cnt2==1){
					for (int i=1;i<=n;i++){
						if (plc2-plc1==to[i] && plc1+nxt[i]<=m && plc1>=frt[i]){
							++res;
						}
					}
					cout<<res<<endl;
					continue;
				}
			}
			st=m,ed=1;
			for (int i=1;i<=m;i++){
				if (s1[i]!=s2[i]){
					st=i;
					break;
				}
			}
			for (int i=m;i>=1;i--){
				if (s1[i]!=s2[i]){
					ed=i; 
					break;
				}
			}
			
			for (int i=1;i<=st;i++){
				for (int j=1;j<=n;j++){
					if (a[j].len+i-1<ed) continue;
					bool flag=0;
					for (int k=0;k<a[j].len;k++){
						if (s1[i+k]!=a[j].s1[k]){
							flag=1;
							break;
						}
					}
					if (flag) continue;
					for (int k=0;k<a[j].len;k++){
						if (s2[i+k]!=a[j].s2[k]){
							flag=1;
							break;
						}
					}
					if (!flag) ++res;
				}
			}
			cout<<res<<endl;
		}
	}
}

