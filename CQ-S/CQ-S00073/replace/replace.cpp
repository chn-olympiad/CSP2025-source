#include<bits/stdc++.h>
#define H1 998244853
#define M1 131
#define H2 1000000007
#define M2 1331
#define ll long long
using namespace std;
struct hsh{
	ll h1=0,h2=0;
};
struct th{
	pair<hsh,pair<hsh,hsh> > a;
	hsh b; 
} thl[200010];
int n,q;
hsh ins(hsh x,char y){
	hsh tmp;
	tmp.h1=(x.h1*M1+y)%H1;
	tmp.h2=(x.h2*M2+y)%H2;
	return tmp;
}
int operator<(hsh x,hsh y){
	if(x.h1==y.h1) return x.h2<y.h2;
	return x.h1<y.h1;
}
int operator==(hsh x,hsh y){
	return x.h1==y.h1&&x.h2==y.h2;
}
int operator<(th x,th y){
	return x.a<y.a;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		string s1,s2;
		cin>>s1>>s2;
		int dl=0,dr=0;
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				dl=i;
				break;
			}
		}
		for(int i=s1.size()-1;i>=0;i--){
			if(s1[i]!=s2[i]){
				dr=i;
				break;
			}
		}
		hsh h1,h2,h3,h4;
		for(int i=dl-1;i>=0;i--) h1=ins(h1,s1[i]);
		for(int i=dl;i<=dr;i++){
			h2=ins(h2,s1[i]);
			h3=ins(h3,s2[i]);
		}
		for(int i=dr+1;i<s1.size();i++) h4=ins(h4,s1[i]);
		thl[i]={make_pair(h1,make_pair(h2,h3)),h4};
	}
	sort(thl+1,thl+n+1);
	while(q--){
		string s1,s2;
		cin>>s1>>s2;
		int dl=0,dr=0;
		for(int i=0;i<s1.size();i++){
			if(s1[i]!=s2[i]){
				dl=i;
				break;
			}
		}
		for(int i=s1.size()-1;i>=0;i--){
			if(s1[i]!=s2[i]){
				dr=i;
				break;
			}
		}
		set<hsh> st;
		hsh h1,h2,h3,h4;
		st.insert(h4);
		for(int i=dl;i<=dr;i++){
			h2=ins(h2,s1[i]);
			h3=ins(h3,s2[i]);
		}
		for(int i=dr+1;i<s1.size();i++){
			h4=ins(h4,s1[i]);
			st.insert(h4);
		}
		int ans=0;
		for(int i=dl;i>=0;i--){
			auto tmp=make_pair(h1,make_pair(h2,h3));
			int l=1,r=n;
			while(l<r){
				int mid=(l+r)/2;
				if(thl[mid].a<tmp) l=mid+1;
				else r=mid;
			}
			while(thl[l].a==tmp){
				ans+=st.count(thl[l].b);
				l++;
			}
			if(i>0) h1=ins(h1,s1[i-1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
