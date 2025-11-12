#include<bits/stdc++.h>
#define int long long
#define mod 998244353ll
#define pb push_back
using namespace std;
inline int read(){
	int x=0,fl=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')fl=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*fl;
}
const int maxn=200010;
const int inf=1e9;

int n,ans;
vector<int> v1,v2,v3;
void work(){
	n=read();ans=0;
	int num1=0,num2=0,num3=0;
	v1.clear(),v2.clear(),v3.clear();
	for(int i=1;i<=n;i++){
		int a=read(),b=read(),c=read();
		if(a==max({a,b,c})){
			num1++;
			v1.pb(a-max(b,c));
		}
		else if(b==max({a,b,c})){
			num2++;
			v2.pb(b-max(a,c));
		}
		else{
			num3++;
			v3.pb(c-max(a,b));
		}
		ans+=max({a,b,c});
	}
	if(num1>n/2){
		sort(v1.begin(),v1.end());
		for(int i=0;i<num1-n/2;i++)ans-=v1[i];
	}
	else if(num2>n/2){
		sort(v2.begin(),v2.end());
		for(int i=0;i<num2-n/2;i++)ans-=v2[i];
	}
	else{
		sort(v3.begin(),v3.end());
		for(int i=0;i<num3-n/2;i++)ans-=v3[i];
	}
	printf("%lld\n",ans);
}

int T;
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	T=read();
	while(T--)work();
}