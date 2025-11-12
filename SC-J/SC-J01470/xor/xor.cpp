#include<bits/stdc++.h>
#define pii pair<int,int>
#define m_p make_pair
#define F first
#define S second
#define mii map<int,int>
#define p_b push_back
using namespace std;
int n,k,a[500005],s=1;
vector<pii>b;
mii mp;
inline bool cmp(pii x,pii y){
	if(x.S==y.S){
		return x.F>y.F;
	}
	return x.S<y.S;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]^=a[i-1];
		if(k==a[i]){
			b.p_b(m_p(mp[0]+1,i));
		}
		else if(mp[k^a[i]]){
			b.p_b(m_p(mp[k^a[i]]+1,i));
		}
		mp[a[i]]=i;
	}
	sort(b.begin(),b.end(),cmp);
	for(int i=1,l=b[0].S;i<b.size();i++){
		if(b[i].F>l){
			s++;
			l=b[i].S;
		}
	}
	cout<<s;
	return 0;
}