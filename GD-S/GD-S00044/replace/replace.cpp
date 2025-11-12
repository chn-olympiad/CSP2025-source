#include<bits/stdc++.h>
#define int long long
#define base 13331
using namespace std;
int n,q;
int hash_num(string s) {
	int sum=0;
	int t_n=s.size();
	s=" "+s;
	for(int i=1;i<=t_n;i++) {
		sum=sum*base+(int)(s[i]);
	}
	return sum;
}
int val1[200005],val2[200005];
void hash_init(string s,int a[]) {
	int t_n=s.size();
	s=" "+s;
	for(int i=1;i<=t_n;i++) {
		a[i]=a[i-1]*base+(int)(s[i]);
	}return;
}int pw[5000005];
int query(int a[],int l,int r) {
	return a[r]-a[l-1]*pw[r-l+1];
}
int a[5000005],b[5000005];

string s1[200005],s2[200005];
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	pw[0]=1;
	for(int i=1;i<=5000000;i++) pw[i]=pw[i-1]*base;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i],val1[i]=hash_num(s1[i]),val2[i]=hash_num(s2[i]);
	while(q--) {
		string t1,t2;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()) {
			cout<<"0\n";continue;
		}
		hash_init(t1,a);
		hash_init(t2,b);
		int len1=t1.size(),len2=t2.size();
		t1=" "+t1,t2=" "+t2;
		int ans=0;
		for(int i=1;i<=n;i++) {
			//val1[i] val2[i]
			for(int j=1;j<=len1;j++) {
				if((j+s1[i].size()-1)>len1) break;
				if(query(a,j,j+s1[i].size()-1)==val1[i] && query(b,j,j+s2[i].size()-1)==val2[i]) {
					bool flag=true;
//					cout<<j<<" "<<i<<endl;
					if(j>=2) {
						if(!(query(a,1,j-1)==query(b,1,j-1))) flag=false;
					}
					if((j+s1[i].size())<=len1) {
//						int ss=s1[i].size(),s
						if(!(query(a,j+s1[i].size(),len1)==query(b,j+s2[i].size(),len1))) flag=false;
					}
					if(flag) ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
