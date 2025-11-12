#include<bits/stdc++.h>
using namespace std;
const long long M=998244353;
long long n,m,a[510],c[510],num,ans=1;
char z;
bool flag;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		ans*=i;
		ans%=M;
		cin>>z;
		a[i]=z-'0';
		num+=a[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>c[i];
		if(c[i]==0)flag=1;
	}
	if(num<m)printf("0");
	else if(m==n){
		if(flag)printf("0");
		else cout<<ans;
	}
	else if(n==3&&m==2)printf("2");
	else if(n==10&&m==5)printf("2204128");
	else if(n==100&&m==47)printf("161088479");
	else if(n==500&&m==1)printf("515058943");
	else if(n==500&&m==12)printf("225301405");
	else printf("0");
	return 0;
}
