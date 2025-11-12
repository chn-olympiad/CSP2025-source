#include<bits/stdc++.h>
using namespace std;
const int N=510;
const int p=998244353;
int n,m,c[N],tot=0,t[N];
string s;
bool ok=1;
bool check(){
//	for(int i=1;i<=n;++i)printf("%d ",t[i]);
//	cout<<endl;
	int fail=0,suc=0;
	for(int i=0;i<n;++i){
//		cout<<"Patience:"<<c[i+1]<<endl;
		if(s[i]=='0'||fail>=c[t[i+1]])fail++;
		else suc++;
	}
//	printf("Suc:%d\n",suc);
	return suc>=m;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%d%d",&n,&m);
	cin>>s;
	for(int i=1;i<=n;++i){
		scanf("%d",&c[i]);
		if(c[i]>0)tot++;
	}
	if(n<=10){
		long long ans=0;
		for(int i=1;i<=n;++i)t[i]=i;
		do{
			if(check())ans++;
		}while(next_permutation(t+1,t+1+n));
		printf("%d",ans);
	}
	if(m==1){
//		printf("Tot:%d\n",tot);
		long long ans=1;
		for(int i=1;i<=n-1;++i)ans*=i,ans%=p;
		printf("%lld",ans*tot%p);
		return 0;
	}
	if(m==n){
		if(tot<n){
			printf("0");
			return 0;
		}
		else{
			long long ans=1;
			for(int i=1;i<=n;++i)ans*=i,ans%=p;
			printf("%lld",ans%p);
			return 0;	
		}
	}
	for(int i=0;i<s.length();++i)ok&=(s[i]-'0');
	if(ok){
		long long ans=1;
		for(int i=1;i<=n;++i)ans*=i,ans%=p;
		printf("%lld",ans);
		return 0;
	}
	return 0;
}

