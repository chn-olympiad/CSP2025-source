#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod1=998244353,mod2=1e9+3,mod3=1e9+7;
int n,q;
struct Hash{
	int v1,v2,v3;
	void m(){
		v1%=mod1,v2%=mod2,v3%=mod3;
	}
	Hash operator *(Hash h){
		Hash hh=(Hash){v1*h.v1,v2*h.v2,v3*h.v3};
		hh.m();
		return hh;
	}
	Hash operator +(Hash h){
		Hash hh=(Hash){v1+h.v1,v2+h.v2,v3+h.v3};
		hh.m();
		return hh;
	}
};
bool operator <(const Hash x,const Hash y){
	return x.v1<y.v1;
}
Hash get(char x,char y){
	int d;
	if(y>=x)
		d=y-x;
	else
		d=(y+26-x);
	if(!d)
		return (Hash){0,0,0};
	return (Hash){(x-'a'+1)*27+d,(x-'a'+1)*27+d,(x-'a'+1)*27+d};
}
map<Hash,vector<int> > mp;
map<Hash,bool> fl,fll;
string a[10010],b[10010];
void wk(){
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=q;i++){
		string aa,bb;
		cin>>aa>>bb;
		int lena=aa.size(),lenb=bb.size(),ans=0;
		if(lena!=lenb){
			cout<<"0"<<'\n';
			continue;
		}
		for(int j=1;j<=n;j++){
			int id=aa.find(a[j]);
			if(id==aa.npos)
				continue;
			string aaa=aa;
			for(int k=id,kk=k-id;kk<a[j].size();aaa[k]=b[j][kk],k++,kk++);
			ans+=(aaa==bb);
		}
		cout<<ans<<'\n';
	}
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	if(q<=1e4){
		wk();
		return 0;
	}
	Hash base=(Hash){27*28,27*28,27*28};
	for(int i=1;i<=n;i++){
		string a,b;
		cin>>a>>b;
		int len=a.size(),l=len-1;
		Hash hh=(Hash){0,0,0};
		for(;a[l]==b[l];l--);
		for(int j=0;j<=l;j++){
			hh=(hh*base);
			hh=(hh+get(a[j],b[j]));
		}
		mp[hh].push_back(len);
		fll[hh]=1;
	}
	for(int i=1;i<=q;i++){
		string a,b;
		cin>>a>>b;
		int len=a.size(),lenb=b.size(),l=len-1;
		if(len!=lenb){
			cout<<"0"<<'\n';
			continue;
		}
		Hash hh=(Hash){0,0,0};
		for(;a[l]==b[l];l--);
		for(int j=0;j<=l;j++){
			hh=(hh*base);
			hh=(hh+get(a[j],b[j]));
		}
		if(!fll[hh]){
			cout<<"0"<<'\n';
			continue;
		}
		if(!fl[hh]){
			sort(mp[hh].begin(),mp[hh].end());
			fl[hh]=1;
		}
		int z=0,y=mp[hh].size()-1;
		if(mp[hh][y]>len)
			for(;y-z>1;){
				int mid=(z+y)>>1;
				if(len>=mp[hh][mid])
					z=mid;
				else
					y=mid;
			}
		else
			y++;
		cout<<y<<'\n';
	}
	return 0;
} 

