#include<bits/stdc++.h>
using namespace std;
#define dbg(x) cerr<<#x":"<<(x)<<' '
#define dbe(x) cerr<<#x":"<<(x)<<'\n'
#define eb emplace_back
#define ep emplace
#define endl '\n'
using ll=long long;
using vi=vector<int>;
using vl=vector<ll>;
using tp=tuple<int,int>;
using ull=unsigned long long;
using vul=vector<ull>;
const int P=131;
const int LEN=5e6;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	vul mi(LEN+1);mi[0]=1;
	for(int i=1;i<=LEN;i++)mi[i]=mi[i-1]*P;
	auto hashstr=[&](const string&s){
		ull hs=0;
		for(auto c:s)hs=hs*P+c;
		return hs;
	};
	//cerr<<hashstr("xa")<<endl;
	auto qjhs=[&](vul&qz,int l,int r){
		if(l>r)return (ull)0;
		if(l==0)return qz[r];
		return qz[r]-qz[l-1]*mi[r-l+1];
	};
	auto hsqz=[&](vul&qz,const string&s){
		qz[0]=s[0];
		for(int i=1;i<s.size();i++){
			qz[i]=qz[i-1]*P+s[i];
		}
	};
	int n,q;
	cin>>n>>q;
	struct S{string s1,s2;ull hs1,hs2;};
	vector<S>a(n);
	for(int i=0;i<n;i++){
		cin>>a[i].s1>>a[i].s2;
		a[i].hs1=hashstr(a[i].s1);
		a[i].hs2=hashstr(a[i].s2);
		//dbg(i),dbg(a[i].hs1),dbe(a[i].hs2);
		//cerr<<222<<endl;
	}
	while(q--){
		string t1,t2;
		cin>>t1>>t2;
		//cerr<<111<<endl;
		vul qz1(t1.size());
		hsqz(qz1,t1);
		ull hst2=hashstr(t2);
		//dbg(qz1[t1.size()-1]),dbe(hst2);
		int ans=0;
		for(int i=0;i<n;i++){
			bool sf=false;
			for(int j=0;j+a[i].s1.size()<=t1.size();j++){
				int r=j+a[i].s1.size()-1;
				ull tmp=qjhs(qz1,j,r);
				//dbg(j),dbg(r),dbe(tmp);
				if(tmp!=a[i].hs1)continue;
				ull mg=(j>0?qz1[j-1]:0)*mi[t1.size()-r-1+a[i].s2.size()]+a[i].hs2*mi[t1.size()-r-1]+qjhs(qz1,r+1,t1.size()-1);
				//dbg(j>0?qz1[j]:0),dbg(t1.size()-r-1+a[i].s2.size()),dbg(t1.size()-r-1),dbe(mg);
				if(mg==hst2){sf=true;break;}
			}
			ans+=sf;
		}
		cout<<ans<<endl;
	}
	return 0;
}