#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod=998244353;

template<typename T>inline void read(T&x){
	x=0; char c; int sign=1;
	do{c=getchar();if(c=='-') sign=-1;}while(!isdigit(c));
	do{x=x*10+c-'0';c=getchar();}while(isdigit(c));
	x*=sign;
}

ll n,m,p[510],c[510],ans,s,sn;
string str;

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	read(n); read(m);
	cin>>str; str=" "+str;
	for(int i=1;i<=n;i++){
		p[i]=i;
		read(c[i]);
	} 
	do{
		s=0;
		sn=0;//no
		for(int i=1;i<=n;i++){
			if(sn>=c[p[i]]){
				sn++;
				continue;
			}
			if(str[i]=='1'){
				s++;
				if(s>=m){
					ans=(ans+1)%mod;
					break;
				}
			} 
			else sn++;
		}
	}while(next_permutation(p+1,p+1+n));
	cout<<ans;
	return 0;
}
