#include<bits/stdc++.h>
using namespace std;
#define ll long long

const int N=200000;
const unsigned ll p1=998244353,p2=1e9+7;

int n,q;
string s[N+1][2+1],t[2+1];
ll pow1[N+1]={1},pow2[N+1]={1};
struct ha{
	unsigned ll m1=0,m2=0;
	void clear() {return m1=m2=0,void();}
	bool empty() {return m1==0&&m2==0;}
	ha operator + (const char x) const {
		return ha{(m1*26+x-'a')%p1,(m2*26+x-'a')%p2};
	}
	ha operator - (const ha x) const {
		return ha{(m1-x.m1+p1)%p1,(m2-x.m2+p2)%p2};
	}
	ha operator ^ (const ll x) const {
		return ha{m1*pow1[x]%p1,m2*pow2[x]%p2};
	}
	void operator += (const char x) {
		return m1=(m1*26+x-'a')%p1,m2=(m2*26+x-'a')%p2,void();
	}
	bool operator < (const ha x) const {
		if(m1!=x.m1) return m1<x.m1;
		return m2<x.m2;
	}
	bool operator == (const ha x) const {
		return m1==x.m1&&m2==x.m2;
	}
}rp[N+1][4],goal[2+1];
int ld[N+1],rd[N+1],lend[N+1],l,r,len;
map<pair<ha,ha>,int> mp;
vector<int> dat[N+1];int cnt;
int ans;
ha sum[5000000+1];
void init(){
	for(int i=1;i<=len;i++)
		sum[i]=sum[i-1]+t[1][i-1];
}
ha query(int l,int r){
	return sum[r+1]-(sum[l]^(r-l+1));
}

signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);
	for(int i=1;i<=N;i++) pow1[i]=pow1[i-1]*26%p1,pow2[i]=pow2[i-1]*26%p2;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>s[i][1]>>s[i][2];
	for(int i=1;i<=n;i++){
		lend[i]=s[i][1].length(),ld[i]=0,rd[i]=lend[i]-1;
		while(ld[i]<lend[i]&&s[i][1][ld[i]]==s[i][2][ld[i]]) ld[i]++;
		while(rd[i]>=ld[i]&&s[i][1][rd[i]]==s[i][2][rd[i]]) rd[i]--;
		for(int j=ld[i];j<=rd[i];j++){
			rp[i][1]+=s[i][1][j];
			rp[i][2]+=s[i][2][j];
		}
		int temp=mp[make_pair(rp[i][1],rp[i][2])];
		if(temp==0) mp[make_pair(rp[i][1],rp[i][2])]=++cnt,temp=cnt;
		dat[temp].push_back(i);
//		cout<<i<<' '<<ld[i]<<' '<<rd[i]<<' '<<temp<<endl;
		mp[make_pair(rp[i][1],rp[i][2])]=temp;
		if(ld[i]<=rd[i]){
			for(int j=0;j<ld[i];j++) rp[i][0]+=s[i][1][j];
			for(int j=rd[i]+1;j<lend[i];j++) rp[i][3]+=s[i][1][j];
		}
	}
	while(q--){
		cin>>t[1]>>t[2];
		goal[1].clear(),goal[2].clear();
		len=t[1].length(),l=0,r=len-1;
		while(l<len&&t[1][l]==t[2][l]) l++;
		while(r>=l&&t[1][r]==t[2][r]) r--;
		for(int j=l;j<=r;j++){
			goal[1]+=t[1][j];
			goal[2]+=t[2][j];
		}
		ans=0;
		init();
		int temp=mp[make_pair(goal[1],goal[2])];
		for(auto i: dat[temp]){
			if(ld[i]>l||lend[i]-rd[i]>len-r) continue;
			if(ld[i]!=0&&(!(query(l-ld[i],l-1)==rp[i][0]))) continue;
			if(rd[i]!=lend[i]-1&&(!(query(r+1,r+lend[i]-rd[i]-1)==rp[i][3]))) continue;
			ans++;
		}
//		ans=dat[temp].size();
		cout<<ans<<endl;
	}
//	cout<<cnt<<endl;
	return 0;
}


/*

uyucqryhrjmrrcmfastozgdyvnnejyokornvimwzaijuqsienpfofktwhydvztgxpavjrp
nhvarpmcurogqsjnsymlzdmvilobyooplzkfvkhegxzrvcygauplfuyfkyakftyyxdsdsw

uyucqryhrjmrrcmfastozgdyvnnejyokornvimwzaijuqsienpfofktwhydvztgxpavjrp
nhvarpmcurogqsjnsymlzdmvilobyooplzkfvkhegxzrvcygauplfuyfkyakftyyxdsdsw

*/