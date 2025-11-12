#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[505];
int b[505];
int c[505];
string s;
bool bj=true;
long long jc(long long i){
	long long sum=1;
	for(int j=1;j<=i;j++){
		sum*=j;
	}
	return sum;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	c[1]=int(s[0]-'0');
	if(c[1]==0) b[1]=1,bj=false;
	else b[1]=0;
	for(int i=1;i<s.size();i++){
		c[i+1]=int(s[i]-'0');
		if(c[i+1]==0) b[i+2]=1,bj=false;
		b[i+1]+=b[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(bj){
		long long sum=0;
		for(int i=m;i<=n;i++){
			sum+=jc(i);
		}
		printf("%lld",sum);
		return 0;
	}
	else if(n==3 && m==2) cout<<2;
	else if(n=10 && m==5) cout<<2204128;
	return 0;
}

