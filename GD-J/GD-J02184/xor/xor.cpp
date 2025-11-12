#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,m[25];
ll k,ans,p[N];
struct node{
	int s[25];
}a[N];
void fj(ll x,int c){
	int o=0;
	while(x>=1){
		a[c].s[o++]=x%2;
		x/=2;
	}
	return;
}
void fjk(ll x){
	int o=0;
	while(x>=1){
		m[o++]=x%2;
		x/=2;
	}
	return;
}
queue<ll>js;
map<ll,ll> os;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	fjk(k);
	for(int i=1;i<=n;i++){
		ll x;
		scanf("%lld",&x);
		fj(x,i);
		for(int j=0;j<=20;j++) a[i].s[j]+=a[i-1].s[j];
	}
	for(int i=1;i<=n;i++){
//		os[0]++;
//		js.push(0);
		ll temp=0,temp2=0;
		for(int j=20;j>=0;j--){
			if(a[i].s[j]%2==1){
				if(m[j]==1) temp2*=10;
				else temp2=temp2*10+1;
			}
			else{
				if(m[j]==1) temp2=temp2*10+1;
				else temp2*=10;
			}
		}
//		cout<<temp2<<" ";
		bool l=0;
		if(os[temp2]||temp2==0){
//			cout<<i<<" ";
			ans++;
			while(!js.empty()){
				os[js.front()]=0;
				js.pop();
			}
			for(int j=0;j<=20;j++) p[j]=a[i].s[j];
			l=1;
		}
		if(!l){
			for(int j=20;j>=0;j--){
				a[i].s[j]-=p[j];
				if(a[i].s[j]%2==1) temp=temp*10+1;
				else temp*=10;
			}
	//		cout<<temp<<"\n";
			os[temp]++;
			js.push(temp);
	//		cout<<temp2<<" ";
		}
		
	}
	printf("%lld",ans);
	return 0;
}
/*
4 2
2 1 0 3
*/
