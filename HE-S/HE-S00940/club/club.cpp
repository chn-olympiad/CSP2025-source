#include<iostream>
#define ll long long
using namespace std;
struct sj{
	ll n;
	ll max =0;
	ll m;
	ll sjj[20000];
	
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ll t,max=0;
	cin>>t;
	for(ll i=0;i<t;i++){
		cout<<i<<endl;
		cin>>sjs[i].n;
		for(ll j=0;j<=sjs[i].n;j++){
			for(ll i=0;i<)
			cin>>sjs[i].sjj[j];
			if(sjs[i].sjj[j]>sjs[i].max)sjs[i].sjj[j]<sjs[i].max=sjs[i].sjj;
		}
	}
	for(ll i=0;i<t;i++){
		ll sub=0;
		for(ll j=0;j<(sjs[i].n/2);j++){
			sub+=sjs[i].m;
		}
		if(sub==3&&sjs.n==4)
		cout <<sub<<endl;
	}
	return 0;
}
