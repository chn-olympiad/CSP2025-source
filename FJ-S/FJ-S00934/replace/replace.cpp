#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}long long n,q,l1,l2,re,si[5201314],f;string s1[5201314],s2[5201314],t1,t2,te,n1,n2;
map<char,char>mp[5201314]; 
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	for(long long i=1;i<=n;++i){
		cin>>s1[i]>>s2[i],l1=s1[i].size();
		for(long long j=0;j<l1;++j)mp[i][s1[i][j]]=s2[i][j];
		si[i]=l1;
	}while(q--){
		re=0,cin>>t1>>t2,l1=t1.size();
		for(long long i=0;i<l1;++i)for(long long j=i;j<l1;++j){
			n1=t1.substr(i,j-i+1),n2=t2.substr(i,j-i+1),l2=n1.size();
			for(long long k=1;k<=n;++k){te=t1;
				if(l2==si[k]){f=1;
					for(long long o=0;o<l2;++o)if(mp[k][n1[o]]!=n2[o]){f=0;break;};
					if(f){for(long long o=i;o<=j;++o)te[o]=n2[o-i];if(te==t2)++re;}
				}
			}
		}printf("%lld\n",re);
	}
}
