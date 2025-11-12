#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define pb push_back
#define qwe(i,l,r) for(int i=l;i<=r;i++)
#define ewq(i,r,l) for(int i=r;i>=l;i--)
ull P=31;
int n,q;
pair<ull,ull>hash[N];
int c[N],d[N],e[N],f[N],m[N];
ull qpow(ull a,ull b){
	ull cnt=1;
	while(b){
		if(b&1)cnt=cnt*a;
		a=a*a;
		b>>=1;
	}
	return cnt;
}
void solve(){
	cin>>n>>q;
	qwe(i,1,n){
		string s1,s2;
		cin>>s1>>s2;
		int len=s1.size();
		m[i]=len;
		s1=' '+s1;s2=' '+s2;
		qwe(j,1,len){
			hash[i].fi=P*hash[i].fi+(s1[j]-'a');
			hash[i].se=P*hash[i].se+(s2[j]-'a');
			//cout<<hash[i].fi<<" "<<hash[i].se<<"\n";
		}
	}
	while(q--){
		int ans=0;
		string a,b;
		cin>>a>>b;
		int len=a.size();
		a=' '+a;b=' '+b;
		c[1]=a[1]-'a',d[1]=b[1]-'a';
		qwe(i,2,len){
			c[i]=c[i-1]*P+a[i]-'a';
			d[i]=d[i-1]*P+b[i]-'a';
		}
		ewq(i,len,1){
			e[i]=e[i+1]*P+a[i]-'a';
			f[i]=f[i+1]*P+b[i]-'a';
		}
		qwe(i,1,n){
		//	cout<<i<<" "<<m[i]<<"\n";
			qwe(j,m[i],len){
				ull sum1=c[j]-qpow(P,m[i])*c[j-m[i]];
				ull sum2=d[j]-qpow(P,m[i])*d[j-m[i]];
		//		cout<<i<<" "<<j<<" "<<sum1<<" & "<<hash[i].fi<<" "<<sum2<<" & "<<hash[i].se<<"\n";
				if(e[j+1]==f[j+1]&&c[j-m[i]]==d[j-m[i]]&&sum1==hash[i].fi&&sum2==hash[i].se){
					ans++;
				}
			}
		}
		cout<<ans<<"\n";
	}
	
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T=1;//cin>>T;
	while(T--)solve();
	return 0;
}
