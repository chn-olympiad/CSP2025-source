#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
const int NR=2e5+5,LR=5e6+5;
int n,q,len[NR],lz[NR],rz[NR],Lz,Rz,Len;
string s[NR][2],t[2];
unordered_map<ULL,vector<int> >T;
ULL md(string x,string y){
	Len=x.size();Lz=Len,Rz=-1;
	for(int j=0;j<Len;j++){
		if(x[j]!=y[j]){
			Lz=min(Lz,j);
			Rz=max(Rz,j);
		}
	}
	ULL hs=0;
	for(int i=Lz;i<=Rz;i++)
		hs=hs*233+x[i];
	for(int i=Lz;i<=Rz;i++)
		hs=hs*233+y[i];
	return hs;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		T[md(s[i][0],s[i][1])].push_back(i);	
		lz[i]=Lz,rz[i]=Rz,len[i]=Len;
	}
	for(int i=1;i<=q;i++){
		cin>>t[0]>>t[1];
		ULL qw=md(t[0],t[1]);
		int ans=0;
		if(T.count(qw)){
			for(int j:T[qw]){
				int flag=0;
				if(lz[j]>Lz||len[j]-rz[j]-1>Len-Rz-1)continue;
				for(int h=1;h<=lz[j];h++){
					if(t[0][Lz-h]!=s[j][0][lz[j]-h]){
						flag=1;
						break;
					}
					if(t[1][Lz-h]!=s[j][0][lz[j]-h]){
						flag=1;
						break;
					}
				}
				if(flag)continue;
				for(int h=1;h<=len[j]-rz[j]-1;h++){
					if(t[0][Rz+h]!=s[j][0][rz[j]+h]){
						flag=1;
						break;
					}
					if(t[1][Rz+h]!=s[j][1][rz[j]+h]){
						flag=1;
						break;
					}
				}
				if(flag)continue;
				ans++;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}