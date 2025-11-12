#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<ull,ull> puu;
const ull p=13331;
const int N=2e5+5;
int n,q;
string s[3],t[3];
int l[N],ll[N];
ull hs[N][3];
ull pp[5000005]={1};
vector<int>v[10003];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=5000001;i++)pp[i]=pp[i-1]*p;
	for(int i=1;i<=n;i++){
		for(int tt=1;tt<3;tt++){
			cin>>s[tt];
			for(int j=0;j<s[tt].size();j++){
				(hs[i][tt]*=p)+=s[tt][j];
			}
		}
		ll[i]=l[i]=s[1].length();
	}
	sort(ll+1,ll+1+n);
	int ln=unique(ll+1,ll+1+n)-ll-1;
	for(int i=1;i<=n;i++){
		v[lower_bound(ll+1,ll+1+ln,l[i])-ll].push_back(i);
	}
	while(q--){
		int ans=0;
		cin>>t[1]>>t[2];
		if(t[1]==t[2]){
			cout<<"1\n";
			continue;
		}
		if(t[1].size()!=t[2].size()){
			cout<<"0\n";
			continue;
		}
		int len=t[1].size();
		int lk[2]={0,len};
		while(lk[0]+1<len&&t[1][lk[0]]==t[2][lk[0]])++lk[0];
		while(lk[1]>0&&t[1][lk[1]-1]==t[2][lk[1]-1])--lk[1];
		for(int i=lower_bound(ll+1,ll+1+ln,lk[1]-lk[0])-ll;i<=ln&&ll[i]<=t[1].size();i++){
			int st=max(0,lk[1]-ll[i]);
			ull ths[3]={0,0,0};
			for(int tt=1;tt<3;tt++){
				for(int j=0;j<ll[i];j++){
					(ths[tt]*=p)+=t[tt][st+j];
				}
			}
			for(int u=0;u<v[i].size();u++)ans+=(hs[v[i][u]][1]==ths[1]&&hs[v[i][u]][2]==ths[2]);
			for(int j=st+1;j<=lk[0];j++){
				for(int tt=1;tt<3;tt++){
					((ths[tt]-=t[tt][j-1]*pp[ll[i]-1])*=p)+=t[tt][j+ll[i]-1];
				}
				for(int u=0;u<v[i].size();u++)ans+=(hs[v[i][u]][1]==ths[1]&&hs[v[i][u]][2]==ths[2]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
