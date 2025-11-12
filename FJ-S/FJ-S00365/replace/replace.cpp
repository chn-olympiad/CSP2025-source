#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
	return x*f;
}
constexpr int e=233,N=2e5+5;
string s,t;
string s1,s2;
unsigned __int128 a1[N],a2[N],q1[N],q2[N];
int n,q,ans;
void ghash(int &p){
	q1[p]=q2[p]=a1[p]=a2[p]=1;
	for(int i=1;i<=s1.size();i++){
		a1[p]=(a1[p]*e+(s1[i-1]-'a'+1));
		a2[p]=(a2[p]*e+(s2[i-1]-'a'+1));
		q1[p]*=(s1[i-1]-'a'+2);
		q2[p]*=(s2[i-1]-'a'+2);
	}
}
void ahash(){
	unsigned __int128 k1=1,k2=1; 
	for(int i=1;i<=s1.size();i++){
		k1*=(s1[i-1]-'a'+2);
		k2*=(s2[i-1]-'a'+2);
	}
	for(int i=1;i<=n;i++){
		if(fabs((ll)(k1*1.0*q2[i]/q1[i]-k2))<=1e-1){
//			cout<<i<<" "<<(ll)k1<<" "<<(ll)q2[i]<<" "<<(ll)q1[i]<<" "<<(ll)k2<<"\n";
			ans++;
		}
	}
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>s1>>s2;
		ghash(i);
	}
	if(n*q<(int)(1e8)){
		for(int i=1;i<=q;i++){
			ans=0;
			cin>>s1>>s2;
			if(s1.size()==s2.size()){
				ahash();
			}
			cout<<ans<<"\n";
		}
	}else for(int i=1;i<=q;i++)cout<<"0\n";
}


