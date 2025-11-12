#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
ull base=127,mod=998244389;
int n,q;
bool isspe(string s){
	int cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]!='a'&&s[i]!='b')return false;
		if(s[i]=='b')cnt++;
	}
	if(cnt!=1)return false;
	return true;
}
unordered_map<ull,int>mp;
pair<int,int> has[200001];
ull calc_has(string s){
	ull val=0;
	for(int i=0;i<s.size();i++){
		val=(val*base%mod+(s[i]-'a'+1))%mod;
	}
	return val;
}
int pan_op(string s,string t){
	for(int i=0;i<s.size();i++){
		if(s[i]==t[i])continue;
		if(s[i]=='b'&&t[i]=='a')return 0;
		if(s[i]=='a'&&t[i]=='b')return 1;
	}
	return -1;
}
struct bit{
	int c[5000001];
	int lowbit(int x){
		return x&-x;
	}
	int sum(int x){
		int sum=0;
		while(x){
			sum+=c[x];
			x-=lowbit(x);
		}
		return sum;
	}
	void modify(int x,int y){
		while(x<=n){
			c[x]+=y;
			x+=lowbit(x);
		}
	}
}bit;
int truans[5000001];
struct que{
	int op,l,r,id;
	que(){};
	que(int xx,int yy,int zz,int yyy){
		op=xx;
		l=yy;
		r=zz;
		id=yyy;
	}
};
bool cmp(que a,que b){
	if(a.l!=b.l)return a.l<b.l;
	else return a.op<b.op;
}
string s[200001],t[200001],qs[200001],qt[200001];
vector<que>point[2][5000001];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	int x=1;
	for(int i=1;i<=n;i++){
		cin>>s[i]>>t[i];
		x&=(isspe(s[i])&isspe(t[i]));
		has[i]={calc_has(s[i]),calc_has(t[i])};
		//cout<<has[i].first<<" "<<has[i].second<<endl;
		mp[has[i].first*mod+has[i].second]++;
	}
if(x==0){
	if(n>1000){
		while(q--)cout<<0<<"\n";
		return 0;
	}
	while(q--){
		string x,y;
		cin>>x>>y;
		int m=x.size(),ld=-1,rd;
		for(int i=0;i<m;i++){
			if(x[i]!=y[i]){
				if(ld==-1)ld=i;
				rd=i;
			}
		}
		int ans=0;
		for(int i=0;i<=ld;i++){
			for(int j=rd;j<m;j++){
				int haa=calc_has(x.substr(i,j-i+1)),hab=calc_has(y.substr(i,j-i+1));
				//cout<<i<<" "<<j<<" "<<haa<<" "<<hab<<endl;
				if(mp.count(haa*mod+hab))ans++;
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
//left,right,gap
for(int i=1;i<=n;i++){
	if(s[i]==t[i])continue;
	int m=s[i].size(),lf=-1,rf,op=1;
	for(int j=0;j<m;j++){
		if(s[i][j]!=t[i][j]){
			if(lf==-1){
				if(s[i][j]=='b')op=0;
			    lf=j;
			}
			rf=j;
		}
	}
	point[op][rf-lf+1].push_back(que(1,lf,m-rf,-1));
}
for(int i=1;i<=q;i++){
	cin>>qs[i]>>qt[i];
	int m=qs[i].size(),lf=-1,rf,op=1;
	for(int j=0;j<m;j++){
		if(qs[i][j]!=qt[i][j]){
			if(lf==-1){
				if(qs[i][j]=='b')op=0;
			    lf=j;
			}
			rf=j;
		}
	}
	point[op][rf-lf+1].push_back(que(2,lf,m-rf,i));
}
for(int op=0;op<=1;op++){
	for(int gap=0;gap<=n;gap++){
		sort(point[op][gap].begin(),point[op][gap].end(),cmp);
		for(auto v:point[op][gap]){
			if(v.op==1){
				bit.modify(v.r,1);
			}else{
				truans[v.id]=bit.sum(v.r);
			}
		}
		for(auto v:point[op][gap]){
			if(v.op==1){
				bit.modify(v.r,-1);
			}
	    }
	}
}
for(int i=1;i<=q;i++)cout<<truans[i]<<"\n";
	return 0;
}
