#include<bits/stdc++.h>
using namespace std;
#define ptt pair<string,string>
#define pii pair<int,int>
typedef long long ll;
const int N=2e5+5,p=998244353,p2=988444333;
int n,q,mi;
map<ptt,int>a;
vector<pii>d[N];
int main(){
	cin.tie(0)->sync_with_stdio(0);cout.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		if(s1==s2)continue;
		int m=s1.size();int l=0,r=m-1;
		while(s1[l]==s2[l])++l;
		while(s1[r]==s2[r])--r;
		ptt s={s1.substr(l,r-l+1),s2.substr(l,r-l+1)};
		if(!a[s])a[s]=++mi;
		int hl=0,hr=0;
		for(int i=l-1;i>=0;i--)hl=((ll)hl*p2+(s1[i]-'a'+1))%p;
		for(int i=r+1;i<m;i++)hr=((ll)hr*p2+(s1[i]-'a'+1))%p;
		//cout<<hl<<' '<<hr<<'\n'; 
		d[a[s]].push_back({hl,hr});
	}
	for(int i=1;i<=q;i++){
		string s1,s2;
		cin>>s1>>s2;
		int m=s1.size(),m2=s2.size();
		if(m!=m2){cout<<'0'<<'\n';continue;}
		int l=0,r=m-1;
		while(s1[l]==s2[l])++l;
		while(s1[r]==s2[r])--r;
		int k=a[{s1.substr(l,r-l+1),s2.substr(l,r-l+1)}];
		map<int,bool>ml,mr;ml.clear();mr.clear();
		int hl=0,hr=0,ans=0;ml[0]=mr[0]=1;
		for(int i=l-1;i>=0;i--)hl=((ll)hl*p2+s1[i]-'a'+1)%p,ml[hl]=1;
		for(int i=r+1;i<m;i++)hr=((ll)hr*p2+s1[i]-'a'+1)%p,mr[hr]=1;
		for(pii x:d[k]){
			if(ml[x.first]&&mr[x.second])++ans;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
