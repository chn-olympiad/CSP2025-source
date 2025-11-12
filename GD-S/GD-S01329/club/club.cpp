#include<bits/stdc++.h>
#define ll long long
#define ios ios::sync_with_stdio(0),cin.tie(0)
using namespace std;
const int N=1e5+5;
struct node{
	int a,b,c;
	int m1,m2,d;
}z[N];
int max(int a,int b){return a>b?a:b;}
bool cmp(node x,node y){
	return x.d>y.d;
}
int n,T;
ll ans;
int len[4];
void solve(){
	cin>>n;ans=0;
	len[1]=len[2]=len[3]=0;
	for(int i=1;i<=n;i++){
		cin>>z[i].a>>z[i].b>>z[i].c;
		int mx=max(z[i].a,max(z[i].b,z[i].c));
		int mi=min(z[i].a,min(z[i].b,z[i].c));
		z[i].m1=mx;
		z[i].m2=z[i].a+z[i].b+z[i].c-mx-mi;
		z[i].d=z[i].m1-z[i].m2;
	}
	sort(z+1,z+n+1,cmp);
	for(int i=1;i<=n;i++){
		int k=z[i].m1;
		if(k==z[i].a){
			if(len[1]==n/2)ans+=z[i].m2*1ll;
			else ans+=k*1ll,len[1]++;
		}
		else if(k==z[i].b){
			if(len[2]==n/2)ans+=z[i].m2*1ll;
			else ans+=k*1ll,len[2]++;
		}
		else{
			if(len[3]==n/2)ans+=z[i].m2*1ll;
			else ans+=k*1ll,len[3]++;
		}
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios;cin>>T;
	while(T--)solve();
	return 0;
}
