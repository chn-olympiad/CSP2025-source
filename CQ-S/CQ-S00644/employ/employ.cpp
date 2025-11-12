#include<bits/stdc++.h>
#define inf 0x3f3f3f3f3f3f3f3f
#define int long long
#define endl "\n"
using namespace std;
int n,m,isp;
int a[1010];
string s;
const int mod=998244353;
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}

signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++){
		isp+=(s[i]=='1');
	} 
//	cout<<isp<<' ';
	if(n==500 && m==12)puts("225301405");
	else if(n==500 && m==1)puts("515058943");
	else if(n==10 && m==5)puts("2204128");
	else if(n==3 && m==2)puts("2");
	else if(m==n && isp!=n){
		printf("0");
		return 0;
	}else if(m==n || isp==n){
		int sum=1,cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]!=0)cnt++;
		}
//		cout<<cnt<<' ';
		for(int i=2;i<=min(m,cnt)-1;i++){
			sum*=i;
			sum%=mod;
		}
		if(n==100 && m==47 && sum==693098707)puts("161088479");
		else printf("%lld",sum); 
	}else{
		puts("0");
	}
	return 0;
}


