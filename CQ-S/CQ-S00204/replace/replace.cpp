#include<bits/stdc++.h>
using namespace std;
const long long N=5*1e6+5;
const long long S=300;
const unsigned long long g=113;
const long long mod=998244853;
//string ss[N],tt[N];
string s,t;
long long l[N],r[N],ll[N];
long long a[N],b[N],c[N],d[N];
long long fa[N],fb[N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	long long n,q;
	cin>>n>>q;
	long long cnt=0;
	for(long long i=1;i<=n;i++){
		cin>>s>>t;
		long long m=s.size();
		long long fl=-1,fr=-2;
		for(long long j=0;j<m;j++){
			if(s[j]!=t[j]){
				fl=j;
				break;
			}
		}
		for(long long j=m-1;j>=0;j--){
			if(s[j]!=t[j]){
				fr=j;
				break;
			}
		}
//		ss[i]=s;
//		tt[i]=t;
		l[i]=fl+1;
		r[i]=m-fr;
		ll[i]=fr-fl+1;
		if(fl!=-1){
			a[i]=0;
			long long p=1;
			for(long long j=fl-1;j>=0;j--){
				a[i]=a[i]+p*((long long)s[j]-'a'+1);
				p*=g;
				p%=mod;
				a[i]%=mod;
			}
			p=1;
			for(long long j=fl;j<=fr;j++){
				b[i]=b[i]+p*((long long)s[j]-'a'+1);
				p*=g;
				p%=mod;
				b[i]%=mod;
			}
			p=1;
			for(long long j=fl;j<=fr;j++){
				d[i]=d[i]+p*((long long)t[j]-'a'+1);
				p*=g;
				p%=mod;
				d[i]%=mod;
			}
			p=1;
			for(long long j=fr+1;j<m;j++){
				c[i]=c[i]+p*((long long)s[j]-'a'+1);
				p*=g;
				p%=mod;
				c[i]%=mod;
			}
		}
//		cout<<i<<":"<<l[i]<<" "<<r[i]<<" "<<a[i]<<" "<<b[i]<<" "<<c[i]<<" "<<d[i]<<endl;
	}
	for(long long i=1;i<=q;i++){
		long long ans=0;
		cin>>s>>t;
		long long m=s.size();
//		long long m=strlen(s);
		long long fl=-1,fr=-2;
		for(long long j=0;j<m;j++){
			if(s[j]!=t[j]){
				fl=j;
				break;
			}
		}
		for(long long j=m-1;j>=0;j--){
			if(s[j]!=t[j]){
				fr=j;
				break;
			}
		}
		fa[fl]=0;
		long long p=1;
		for(long long j=fl-1;j>=0;j--){
			fa[j]=fa[j+1]+p*((long long)s[j]-'a'+1);
			p*=g;
			p%=mod;
			fa[j]%=mod;
		}
		long long q=0,qq=0;
		p=1;
		for(long long j=fl;j<=fr;j++){
			q=q+p*((long long)s[j]-'a'+1);
			p*=g;
			p%=mod;
			q%=mod;
		}
		p=1;
		for(long long j=fl;j<=fr;j++){
			qq=qq+p*((long long)t[j]-'a'+1);
			p*=g;
			p%=mod;
			qq%=mod;
		}
		p=1;
		fb[fr]=0;
		for(long long j=fr+1;j<m;j++){
			fb[j]=fb[j-1]+p*((long long)s[j]-'a'+1);
			p*=g;
			p%=mod;
			fb[j]%=mod;
		}
//		cout<<q<<" "<<qq<<endl;
		for(long long j=1;j<=n;j++){
			if(l[j]==0){
				continue;
			}
			if(q==b[j]&&qq==d[j]&&ll[j]==fr-fl+1){
//				cout<<j<<"!"<<" "<<fl<<" "<<fr<<" "<<fl-l[j]+1<<" "<<fr+r[j]-1<<endl;
				if(fl-l[j]+1>=0&&fr+r[j]-1<m){
					long long aaa=fa[fl-l[j]+1];
					aaa=(aaa%mod+mod)%mod;
					long long bb=fb[fr+r[j]-1];
//					cout<<aaa<<" "<<bb<<endl;
					bb=(bb%mod+mod)%mod;
					if(aaa==a[j]&&bb==c[j]){
						ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
} 
/*
4 2
aabcxxx gadexxx
ab cd
bc de
aa bb
xxxabcxxx xxxadexxx
aaaa bbbb
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb
*/
