#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N=5000010;
int n,m,len[N],Len;
const int p1=131,p2=13331;
string s[200010],t[200010],strs,strt;
ull Hs1[N],Hs2[N],pw1[N],pw2[N];
struct Node{
	ull sx,tx;
	int fir,lst;
}a[N];
pair<ull,ull> get(int l,int r){
	return {Hs1[r]-Hs1[l-1]*pw1[r-l+1],Hs2[r]-Hs2[l-1]*pw2[r-l+1]};
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	pw1[0]=pw2[0]=1;
	for(int i=1;i<=N-10;i++) pw1[i]=pw1[i-1]*p1,pw2[i]=pw2[i-1]*p2;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];len[i]=s[i].size();
//		cout<<s[i]<<' '<<t[i]<<' ';
		s[i]=' '+s[i];t[i]=' '+t[i];
		for(int j=1;j<=len[i];j++){
			a[i].sx=a[i].sx*p1+s[i][j],a[i].tx=a[i].tx*p2+t[i][j];
			if(s[i][j]!=t[i][j]) a[i].lst=j,a[i].fir=a[i].fir?a[i].fir:j;
		}
//		cout<<a[i].fir<<' '<<a[i].lst<<endl;
	}
	while(m--){
		cin>>strs>>strt;
		if(strs.size()!=strt.size()){
			cout<<"0\n";
			continue;
		} 
		Len=strs.size();strs=' '+strs;strt=' '+strt;
		int Fir=0,Lst;
		for(int j=1;j<=Len;j++){
			if(strs[j]!=strt[j]) Lst=j,Fir=Fir?Fir:j;
			Hs1[j]=Hs1[j-1]*p1+strs[j];Hs2[j]=Hs2[j-1]*p2+strt[j];
		}
//		cout<<Fir<<' '<<Lst<<endl;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(Fir-a[i].fir+1<0||Fir-a[i].fir+len[i]>Len||a[i].lst-a[i].fir!=Lst-Fir||!a[i].fir) continue;
			if(get(Fir-a[i].fir+1,Fir-a[i].fir+len[i])==make_pair(a[i].sx,a[i].tx)){
//				cout<<i<<' '<<a[i].fir<<' '<<a[i].lst<<'\n';
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

