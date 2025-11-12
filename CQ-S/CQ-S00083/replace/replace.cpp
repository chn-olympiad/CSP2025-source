#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef unsigned long long ullong;
const int MaxN=200000,MaxS=1e7+100;
const ullong Base1=1145141,Mod1=1e9+7,Base2=1145143,Mod2=998244353;
int n,q,shl[MaxN+1];
ullong parr1[MaxS+1],parr2[MaxS+1];
ullong PMod(ullong x,const ullong&mod){return x>=mod?x-=mod:x;}
struct Hasher{
	vector<ullong>pre1,pre2;
	int len;
	void Make(const string&s){
		len=s.size();
		pre1.resize(s.size());
		pre2.resize(s.size());
		pre1[0]=pre2[0]=s[0];
		for(int i=1;i<s.size();i++)pre1[i]=PMod(pre1[i-1]*Base1%Mod1+s[i],Mod1);
		for(int i=1;i<s.size();i++)pre2[i]=PMod(pre2[i-1]*Base2%Mod2+s[i],Mod2);
	}
	pair<ullong,ullong>Pick(int l,int r){
		if(l==0)return make_pair(pre1[r],pre2[r]);
		return make_pair(
			PMod(pre1[r]-pre1[l-1]*parr1[r-l+1]%Mod1+Mod1,Mod1),
			PMod(pre2[r]-pre2[l-1]*parr2[r-l+1]%Mod2+Mod2,Mod2)
		);
	}
};
string inp1[MaxN+1],inp2[MaxN+1],inp3[MaxN+1],inp4[MaxN+1];
pair<ullong,ullong>sh[MaxN+1];
bool Check(const string&s){
	int cnt=0;
	for(char c:s){
		if(c!='a'&&c!='b')return false;
		if(c=='b')cnt++;
	}
	return cnt==1;
}
namespace OttoSolve{
//int deltafroce[MaxN+1],,,;zycscncycs
//void Solve(){
//	for(int i=1;i<=n;i++){
//		int p1,p2;
//		for(int j=0;j<inp1[i].size();j++){
//			if(inp1[j]=='b'){
//				p1=j;
//				break;
//			}
//		}
//		for(int j=0;j<inp2[i].size();j++){
//			if(inp2[j]=='b'){
//				p2=j;
//				break;
//			}
//		}
//	}
//}
}
void Solve(){
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>inp1[i]>>inp2[i];
	for(int i=1;i<=q;i++)cin>>inp3[i]>>inp4[i];
//	bool flag=true;
//	for(int i=1;i<=n&&flag;i++)flag&=Check(inp1[i]);
//	for(int i=1;i<=n&&flag;i++)flag&=Check(inp2[i]);
//	for(int i=1;i<=q&&flag;i++)flag&=Check(inp3[i]);
//	for(int i=1;i<=q&&flag;i++)flag&=Check(inp4[i]);
//	if(flag)return OttoSolve::Solve();
	parr1[0]=parr2[0]=1;
	for(int i=1;i<=MaxS;i++)parr1[i]=parr1[i-1]*Base1%Mod1;
	for(int i=1;i<=MaxS;i++)parr2[i]=parr2[i-1]*Base2%Mod2;
	for(int i=1;i<=n;i++){
		string s,s1=inp1[i],s2=inp2[i];
		for(int i=0;i<s1.size();i++)s+=s1[i],s+=s2[i];
		Hasher shh;
		shh.Make(s);
		sh[i]=shh.Pick(0,shh.len-1);
		shl[i]=s.size();
	}
	for(int i=1;i<=q;i++){
		string t1=inp3[i],t2=inp4[i];
		int lx=-1,rx=-1;
		for(int i=0;i<t1.size();i++){
			if(t1[i]!=t2[i]){
				lx=i;
				break;
			}
		}
		for(int i=t1.size()-1;i>=0;i--){
			if(t1[i]!=t2[i]){
				rx=i;
				break;
			}
		}
		if(lx==-1||rx==-1){
			cout<<0<<'\n';
			continue;
		}
		string t;
		for(int i=0;i<t1.size();i++)t+=t1[i],t+=t2[i];
		lx*=2,rx*=2;
		Hasher th;
		th.Make(t);
//		cout<<t<<' '<<lx<<' '<<rx<<'\n';
//		cout<<sh[3].first<<' '<<th.Pick(4,7).first<<'\n';
		int ans=0;
		for(int i=1;i<=n;i++){
//			cout<<min(ullong(lx),t.size()-shl[i])<<'!'<<'\n';
			for(int j=max(0ll,rx-shl[i]+2);j<=min(lx,(int)t.size()-shl[i]);j+=2){
//				cout<<i<<' '<<j<<','<<j+shl[i]-1<<
//				':'<<sh[i].first<<' '<<th.Pick(j,j+shl[i]-1).first<<'\n';
				if(sh[i]==th.Pick(j,j+shl[i]-1))ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
#undef int
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
//	int T;
//	cin>>T;
//	while(T--)
		Solve();
	return 0;
}

