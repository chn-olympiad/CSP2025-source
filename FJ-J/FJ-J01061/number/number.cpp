#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f; 
}string s;long long a[5201314],d;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	for(long long i=0;i<s.size();++i)if(s[i]>='0'&&s[i]<='9')a[++d]=s[i]-'0';
	sort(a+1,a+d+1,greater<long long>());
	for(long long i=1;i<=d;++i)printf("%lld",a[i]);
} 
