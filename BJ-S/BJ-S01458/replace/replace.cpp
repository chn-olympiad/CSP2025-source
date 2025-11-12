#include<bits/stdc++.h>
#define N 200005
#define pii pair<int,int>
#define mk make_pair
#define int long long
#define ull unsigned long long
using namespace std;
int n,q,pos1,pos2,d1,dd[N],cnt=0,ii=0,ans=0;
ull base=300,mod[2]={1777777777,777777997};
string s[N][2],t1,t2;
unordered_map<int,vector<pii> >mmap;
bool A=0;
struct hash2{
	string s;
	int len;
	vector<ull>h[2],pmod[2];
	hash2(string s1){
		s=s1;len=s.size();
		for(int j=0;j<2;j++){
			h[j].clear();h[j].resize(len+1);
			pmod[j].clear();pmod[j].resize(len+1);
			h[j][0]=0;pmod[j][0]=1;
			for(int i=1;i<=len;i++){
				h[j][i]=(h[j][i-1]*base+s[i-1])%mod[j];
				pmod[j][i]=(pmod[j][i-1]*base)%mod[j];
			}
		}
	}
	pii get(int l,int r){
		vector<ull>f(2);
		for(int j=0;j<2;j++){
			f[j]=(h[j][r]-(h[j][l-1]*pmod[j][r-l+1]%mod[j])+mod[j])%mod[j];
		}
		return make_pair(f[0],f[1]);
	}
};
void solA(){
	ans=0;
	hash2 h1(t1),h2(t2);
	t1="A"+t1;t2="C"+t2;
	if(t1.size()!=t2.size()){cout<<0<<'\n';return;}
	pos1=pos2=-1;
	for(int i=1;i<t1.size();i++){
		if(t1[i]!=t2[i]&&pos1==-1)pos1=i;
		if(t1[i]==t2[i]&&pos1!=-1)pos2=i;
	}
	pos2--;
	if(pos2==-1)pos2=t1.size()-1;
	d1=pos2-pos1;
	for(int i=1;i<=n;i++){
		hash2 h3(s[i][0]),h4(s[i][1]);
		for(int j=0;j<s[i][0].size();j++){
			if(h3.get(j+1,j+d1+1)==h1.get(pos1,pos2)&&h4.get(j+1,j+d1+1)==h2.get(pos1,pos2)){
				if(h3.get(1,s[i][0].size())==h1.get(pos1-j,pos2+(s[i][0].size()-j-d1-1)))ans++;
			}
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	if(q==1){
		for(int i=1;i<=n;i++)cin>>s[i][0]>>s[i][1];
		cin>>t1>>t2;
		solA();
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>s[i][0]>>s[i][1];
		for(int j=0;j<s[i][0].size();j++){
			if(s[i][0][j]=='b')pos1=j;
			if(s[i][1][j]=='b')pos2=j;
			if(s[i][1][j]!='a'&&s[i][1][j]!='b')A=1;
		}
		d1=pos1-pos2;
		if(!mmap.count(d1)){
			dd[cnt]=d1;
			cnt++;
		}
		mmap[d1].push_back(mk(pos1,s[i][0].size()-pos1));
	}
	if(A){
		while(q--){
			cin>>t1>>t2;
			solA();
		}
		return 0;
	}
	for(int i=0;i<cnt;i++)sort(mmap[dd[i]].begin(),mmap[dd[i]].end());
	while(q--){
		ii++;
		cin>>t1>>t2;
		if(t1.size()!=t2.size()){cout<<"0\n";continue;}
		for(int i=0;i<t1.size();i++){
			if(t1[i]=='b')pos1=i;
			if(t2[i]=='b')pos2=i;
		}
		d1=pos1-pos2;
		if(!mmap.count(d1)){cout<<"0\n";continue;}
		ans=0;
		for(int i=0;i<mmap[d1].size();i++){
			if(mmap[d1][i].first>pos1)break;
			if(mmap[d1][i].second>t1.size()-pos1)continue;
			ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
