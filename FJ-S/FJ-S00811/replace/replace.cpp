#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#define int long long
using namespace std;
const int N=2e5;
const int B1=131;
const int B2=47;
const int B3=137;
struct haha{
	int h1,h2,h3;
	haha(){};
	haha(int h1,int h2,int h3){
		this->h1=h1;
		this->h2=h2;
		this->h3=h3;
	}
	operator ==(const haha rhs)const{
		return this->h1==rhs.h1&&this->h2==rhs.h2&&this->h3==rhs.h3;
	}
	operator <(const haha rhs)const{
		if(this->h1==rhs.h1){
			if(this->h2==rhs.h2)return this->h3<rhs.h3;
			return this->h2<rhs.h2;
		}
		return this->h1<rhs.h1;
	}
}a[N+5];
int has[5000005],hascnt=0;
int dif[N+5];
inline int h(int base){
	int res=0;
	for(int i=1;i<=hascnt;i++)res*=base,res+=has[i]-has[1]+1;
	return res;
}
string s1[N+5],s2[N+5];
string q1,q2;
int len[N+5];
int n,q;
map<haha,int>mm;
vector<int>G[N+5];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>s1[i]>>s2[i],len[i]=s1[i].length();
	for(int i=1;i<=n;i++){
		hascnt=0;
		for(int j=0;j<len[i];j++)if(s1[i][j]!=s2[i][j])has[++hascnt]=j;
		a[i]=haha(h(B1),h(B2),h(B3));
		dif[i]=has[1]+1;
	}
	int k=0;
	for(int i=1;i<=n;i++){
		if(mm[a[i]]==0)mm[a[i]]=++k;
		G[mm[a[i]]].push_back(i);
	}
	while(q--){
		int ans=0;
		cin>>q1>>q2;
		hascnt=0;
		int ll=q1.length();
		for(int j=0;j<ll;j++)if(q1[j]!=q2[j])has[++hascnt]=j;
		haha u=haha(h(B1),h(B2),h(B3));
		int diff=has[1]+1;
		for(int i:G[mm[u]]){
			int flag=1;
			for(int j=0;j<len[i];j++){
				if(s1[i][j]!=q1[j+diff-dif[i]])flag=0;
			}
			for(int j=0;j<len[i];j++){
				if(s2[i][j]!=q2[j+diff-dif[i]])flag=0;
			}
			ans+=flag;
		}
		cout<<ans<<endl;
	}
}
