#include<bits/stdc++.h>
#define ll long long
using namespace std;
/*
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19

*/ 

const ll mod=998244353;

ll n,m;
char s[505];//每一天的面试题难度 
//均为1 
ll c[505];//每个人的耐心上限 

void n1(){
	ll n_=1,m_=1;
	//cout<<n-m+1<<endl;
	for(ll i=n-m+1;i<=n;i++){
		n_=n_*i;
		//if(n_<0) n_=-n_;
		//cout<<"n_:"<<n_<<endl;
		n_%=mod;
	}
	for(ll i=1;i<=m;i++){
		m_=m_*i;
		//if(m_<0) m_=-m_;
		//cout<<"m_:"<<m_<<endl;
		m_%=mod;
	}
	//cout<<n_%mod<<" "<<m_%mod<<endl;
	ll result=(n_%mod)/(m_%mod);
	//cout<<"result:"<<result<<endl;
	printf("%lld\n",result%mod);
}


int main() {
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;i++) cin>>s[i];
	for(ll i=1;i<=n;i++) scanf("%lld",&c[i]);
	n1();
	return 0;
}

