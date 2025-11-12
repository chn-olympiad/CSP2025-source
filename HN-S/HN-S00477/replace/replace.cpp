#include<bits/stdc++.h>
#define f(i,l,r) for(int i=l;i<=r;++i)
#define F(i,r,l) for(int i=r;i>=l;--i)
#define LL long long
#define ULL unsigned long long
#define read(n) {int _x=0,_t=1;char _c=getchar();while(!isdigit(_c)){if(_c=='-')_t=-1;_c=getchar();}while(isdigit(_c))_x=_x*10+_c-'0',_c=getchar();n=_x*_t;}
using namespace std;
const int N=200005;
int n,q;
string s1[N],s2[N],t1,t2;
map<string,string> mp;
bool pd(int l,int r){
	for(int i=0;i<l;++i) if(t1[i]!=t2[i]) return 0;
	for(int i=r+1;i<t1.size();++i) if(t1[i]!=t2[i]) return 0;
	return 1;
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	read(n);read(q);
	f(i,1,n){
		cin>>s1[i]>>s2[i];
		mp[s1[i]]=s2[i];
	}
	if(n>10000){
		f(i,1,q){
			printf("0\n");
		}
		return 0;
	}
	while(q--){
		int ans=0;
		cin>>t1>>t2;
		for(int i=0;i<t1.size();++i){
			string T1,T2;
			for(int len=0;i+len<t1.size();++len){
				T1+=t1[i+len],T2+=t2[i+len];
				if(mp[T1]==T2&&pd(i,i+len)){
					++ans;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

