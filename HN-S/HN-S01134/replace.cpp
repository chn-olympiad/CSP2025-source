#include<bits/stdc++.h>
using namespace std;
#define int long long
const int base=131;
const int mod=1e16+2137;
int n,q,len[2],LEN;
string s,S;
unsigned int hs[5000005][2],pw[5000005];
// map<tuple<int,int,int>,int> mp;
map<pair<int,int>,vector<int> > mp;
map<pair<pair<int,int>,pair<int,int> >,int> sum;
vector<int> V;
struct node{
	int L,R,val1,val2,vall,valr,len;
}a[5000005];
int query(int l,int r,bool f){return (hs[r][f]+(mod-(__int128)hs[l-1][f]*pw[r-l+1]%mod))%mod;}
void init(string &s,bool f){
	len[f]=s.size(),s=" "+s;
	for(int i=1; i<=len[f]; i++) hs[i][f]=(hs[i-1][f]*base+s[i])%mod;
	return;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pw[0]=1;
	for(int i=1; i<=5000000; i++) pw[i]=pw[i-1]*base%mod;
	cin>>n>>q;
	LEN=300;
	for(int i=1; i<=n; i++){
		cin>>s>>S;
		init(s,0),init(S,1);
		int lt=0,rt=len[0]+1;
		while(lt+1<rt){
			int mid=lt+rt>>1;
			if(query(1,mid,0)==query(1,mid,1)) lt=mid;
			else rt=mid;
		}
		if(lt==len[0]){a[i].L=(int)1e18;continue;}
		a[i].L=lt;
		lt=0,rt=len[0]+1;
		while(lt+1<rt){
			int mid=lt+rt>>1;
			if(query(mid,len[0],0)==query(mid,len[0],1)) rt=mid;
			else lt=mid;
		}
		a[i].R=rt;
		a[i].val1=query(a[i].L+1,a[i].R-1,0),a[i].val2=query(a[i].L+1,a[i].R-1,1);
		a[i].vall=query(1,a[i].L,0);
		a[i].valr=query(a[i].R,len[0],0);
		a[i].len=len[0];
		mp[{a[i].val1,a[i].val2}].push_back(i);
		sum[{{a[i].vall,a[i].valr},{a[i].val1,a[i].val2}}]++;
	}
	while(q--){
		cin>>s>>S;
		init(s,0),init(S,1);
		int lt=0,rt=len[0]+1,L,R;
		while(lt+1<rt){
			int mid=lt+rt>>1;
			if(query(1,mid,0)==query(1,mid,1)) lt=mid;
			else rt=mid;
		}
		L=lt;
		lt=0,rt=len[0]+1;
		while(lt+1<rt){
			int mid=lt+rt>>1;
			if(query(mid,len[0],0)==query(mid,len[0],1)) rt=mid;
			else lt=mid;
		}
		R=rt;
		int sum1=query(L+1,R-1,0),sum2=query(L+1,R-1,1),ans=0;
		if(q==1||mp[{sum1,sum2}].size()<=500||len[0]>=LEN){
			V=mp[{sum1,sum2}];
			for(int i:V){
				if(a[i].L==(int)1e18) continue;
				if(L<a[i].L||len[0]-R+1<a[i].len-a[i].R+1) continue;
				if(query(L-a[i].L+1,L,0)!=a[i].vall||query(R,R+(a[i].len-a[i].R+1)-1,0)!=a[i].valr) continue;
				ans++;
			}
			cout<<ans<<'\n';
		}
		else{
			for(int l=1; l<=L+1; l++) for(int r=R-1; r<=len[0]; r++) ans+=sum[{{query(l,L,0),query(R,r,0)},{sum1,sum2}}];
			cout<<ans<<'\n';
		}
	}
	return 0;
}