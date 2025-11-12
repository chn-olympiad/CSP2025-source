#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	n=read();
	m=read();
	string ss;
	cin>>ss;
	for(int i=0;i<n;i++){
		int c=read();
	}
	int ans=0;
	int nn=1;
	for(int j=n;j>=1;j--){
			nn=nn*j;
	}
	cout<<nn%mod;
	return 0;
}
